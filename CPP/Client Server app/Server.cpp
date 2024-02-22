// Server.cpp
#include "Server.h"
#include "SocketUtils.h"

#include <iostream>
#include <vector>

Server::Server(int port) : port(port), serverSocket(CreateServerSocket(port)) {}

Server::~Server() {
    Stop();
}

void Server::Start() {
    std::vector<int> clientSockets;

    while (clientSockets.size() < 100) {
        int clientSocket = AcceptClientConnection(serverSocket);

        if (clientSocket != -1) {
            clientSockets.push_back(clientSocket);
            std::cout << "Client connected. Total clients: " << clientSockets.size() << std::endl;

            // Handle the client in a separate thread or process
            // For simplicity, we handle the client in the same thread here
            HandleClient(clientSocket);
        }
    }
}

void Server::Stop() {
    CloseSocket(serverSocket);
}

void Server::HandleClient(int clientSocket) {
    // Implement your logic to handle the client here
    // For example, receive and send messages
    std::string message = ReceiveData(clientSocket);
    std::cout << "Received message from client: " << message << std::endl;

    // Send a response
    SendData(clientSocket, "Message received. Thank you!");

    // Close the client socket
    CloseSocket(clientSocket);
}
