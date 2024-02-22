// ConcreteHandler.cpp
#include "ConcreteHandler_Solid.h"
#include "SocketUtils.h"

#include <iostream>

void ConcreteHandler::Handle(int clientSocket) {
    // Implement your logic to handle the client here
    // For example, receive and send messages
    std::string message = SocketUtils::ReceiveData(clientSocket);
    std::cout << "Received message from client: " << message << std::endl;

    // Send a response
    SocketUtils::SendData(clientSocket, "Message received. Thank you!");
}
