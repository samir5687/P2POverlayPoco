#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <iostream>

int main() {
    Poco::Net::ServerSocket server(9090);
    std::cout << "Server listening on port 9090..." << std::endl;

    for (;;) {
        Poco::Net::StreamSocket client = server.acceptConnection();
        Poco::Net::SocketStream stream(client);
        stream << "Welcome to the P2P Overlay!\n";
    }

    return 0;
}
