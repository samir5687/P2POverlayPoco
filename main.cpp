#include <iostream>
#include "ServerManager.h"

int main() {
    ServerManager server;
    server.start(9090);
    return 0;
}