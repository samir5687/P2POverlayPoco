#include <iostream>
#include "client.h"

int main() {
    Client client("localhost", 9090);
    client.sendMessage("REGISTER:Client1");
    return 0;
}