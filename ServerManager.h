#ifndef SERVER_MANAGER_H
#define SERVER_MANAGER_H

#include <Poco/Net/StreamSocket.h>
#include <map>
#include <string>

class ServerManager {
public:
    void start(int port);
private:
    void handleClient(Poco::Net::StreamSocket socket);
    std::map<std::string, Poco::Net::StreamSocket> clients;
};

#endif