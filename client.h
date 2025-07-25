#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    Client(const std::string& host, int port);
    void sendMessage(const std::string& message);
};

#endif