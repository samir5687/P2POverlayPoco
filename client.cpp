#include "client.h"
#include <Poco/Net/SocketStream.h>
#include <iostream>

ClientHandler::ClientHandler(Poco::Net::StreamSocket client)
    : _client(client) {}

void ClientHandler::run() {
    try {
        Poco::Net::SocketStream stream(_client);
        std::cout << "Client connected: " << _client.peerAddress().toString() << std::endl;

        stream << "Welcome! Send 'REGISTER' to join the overlay." << std::endl;

        std::string message;
        while (std::getline(stream, message)) {
            if (message == "REGISTER") {
                std::cout << "Node registered: " << _client.peerAddress().toString() << std::endl;
                stream << "REGISTERED: " << _client.peerAddress().toString() << std::endl;
            } else {
                std::cout << "Received: " << message << std::endl;
                stream << "Echo: " << message << std::endl;
            }
        }
    } catch (Poco::Exception& ex) {
        std::cerr << "Client error: " << ex.displayText() << std::endl;
    }
}
