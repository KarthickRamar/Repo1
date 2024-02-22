// Client.cpp
#include "Client.h"
#include "SocketUtils.h"

#include <iostream>

Client::Client(const char* serverAddress, int port) : serverAddress(serverAddress), port(port) {
    clientSocket = CreateClientSocket(serverAddress, port);
}

Client::~Client() {
    Disconnect();
}

void Client::Connect() {
    std::cout << "Connecting to the server..." << std::endl;
    // Connect to the server
    // Handle errors appropriately in a production environment
}

void Client::Disconnect() {
    CloseSocket(clientSocket);
}

void Client::SendMessage(const char* message) {
    // Send a message to the server
    SendData(clientSocket, message);

    // Receive and print the response
    std::string response = ReceiveData(clientSocket);
    std::cout << "Server response: " << response << std::endl;
}
