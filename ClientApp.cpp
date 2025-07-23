#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/SocketStream.h>
#include <iostream>

int main() {
    try {
        Poco::Net::SocketAddress serverAddr("127.0.0.1", 9090);
        Poco::Net::StreamSocket socket(serverAddr);
        Poco::Net::SocketStream stream(socket);

        std::cout << "Connected to server." << std::endl;

        // Send registration message
        stream << "REGISTER" << std::endl;
        stream.flush();

        std::string response;
        std::getline(stream, response);
        std::cout << "Server: " << response << std::endl;

        // Then interact with server
        std::string input;
        while (true) {
            std::cout << "> ";
            std::getline(std::cin, input);
            if (input == "exit") break;

            stream << input << std::endl;
            stream.flush();

            std::getline(stream, response);
            std::cout << "Server: " << response << std::endl;
        }
    } catch (Poco::Exception& ex) {
        std::cerr << "Client error: " << ex.displayText() << std::endl;
    }
    return 0;
}
