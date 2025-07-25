#include "client.h"
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/SocketStream.h>
#include <iostream>

using namespace Poco::Net;
using namespace std;

Client::Client(const string& host, int port) {
    SocketAddress sa(host, port);
    StreamSocket socket(sa);
    SocketStream stream(socket);
    stream << "REGISTER:Client1" << endl;
    cout << "Client sent registration." << endl;
}

void Client::sendMessage(const string& message) {
    // Placeholder for sending messages
}