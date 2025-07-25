#include "ServerManager.h"
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/Thread.h>
#include <iostream>

using namespace Poco::Net;
using namespace std;

void ServerManager::start(int port) {
    ServerSocket server(port);
    cout << "Server listening on port " << port << "..." << endl;

    while (true) {
        StreamSocket client = server.acceptConnection();
        handleClient(client);
    }
}

void ServerManager::handleClient(StreamSocket socket) {
    SocketStream str(socket);
    string message;
    str >> message;

    if (message.find("REGISTER:") == 0) {
        string clientID = message.substr(9);
        clients[clientID] = socket;
        cout << "Client registered: " << clientID << endl;
    }
}