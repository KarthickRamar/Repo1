// Server.cpp
#include "Server.h"
#include "SocketUtils.h"

#include <iostream>
#include <vector>
#include <thread>

Server::Server(int port) : port(port), serverSocket(SocketUtils::CreateServerSocket(port)) {}

Server::~Server() {
    Stop();
}

void Server::Start() {
    while (true) {
        int clientSocket = SocketUtils::AcceptClientConnection(serverSocket);

        if (clientSocket != -1) {
            std::cout << "Client connected. Creating a new thread to handle it.\n";

            // Create a new thread to handle the client
            std::thread clientThread(&Server::HandleClient, this, clientSocket);
            clientThreads.push_back(std::move(clientThread));

            // Detach the thread to allow it to run independently
            clientThread.detach();
        }
    }
}

void Server::Stop() {
    SocketUtils::CloseSocket(serverSocket);

    // Wait for all client threads to finish
    for (auto& thread : clientThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

void Server::HandleClient(int clientSocket) {
    try {
        // Implement your logic to handle the client here
        // For example, receive and send messages
        std::string message = SocketUtils::ReceiveData(clientSocket);
        std::cout << "Received message from client: " << message << std::endl;

        // Send a response
        SocketUtils::SendData(clientSocket, "Message received. Thank you!");
    } catch (const std::exception& e) {
        std::cerr << "Error handling client: " << e.what() << std::endl;
    }

    // Close the client socket
    SocketUtils::CloseSocket(clientSocket);
}
