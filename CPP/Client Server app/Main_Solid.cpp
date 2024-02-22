#include "Server.h"
#include "ConcreteHandler.h"

int main() {
    ConcreteHandler concreteHandler;
    Server server(12345, &concreteHandler);
    server.Start();
    return 0;
}
