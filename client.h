#pragma once
#include <Poco/Net/StreamSocket.h>
#include <Poco/Runnable.h>

class ClientHandler : public Poco::Runnable {
public:
    explicit ClientHandler(Poco::Net::StreamSocket client);
    void run() override;

private:
    Poco::Net::StreamSocket _client;
};
