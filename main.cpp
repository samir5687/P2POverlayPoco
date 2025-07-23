#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/ThreadPool.h>
#include <Poco/Runnable.h>
#include <iostream>
#include "client.h" // Include your ClientHandler class

using namespace Poco::Net;
using namespace Poco;

int main() {
    try {
        ServerSocket server(9090);  // Server will listen on port 9090
        std::cout << "Server listening on port 9090..." << std::endl;

        while (true) {
            StreamSocket client = server.acceptConnection();
            std::cout << "New client connected!" << std::endl;

            ClientHandler* handler = new ClientHandler(client);
            ThreadPool::defaultPool().start(*handler);
        }
    } catch (Poco::Exception& ex) {
        std::cerr << "Server error: " << ex.displayText() << std::endl;
        return 1;
    }

    return 0;
}
