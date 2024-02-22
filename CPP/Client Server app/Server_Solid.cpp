// Server.cpp
#include "Server_Solid.h"
#include "SocketUtils.h"

#include <iostream>
#include <vector>
#include <thread>

Server::Server(int port, ClientHandler* handler) : port(port), serverSocket(SocketUtils::CreateServerSocket(port)), clientHandler(handler) {}

Server::~Server() {
    Stop();
}

void Server::Start() {
    while (true) {
        int clientSocket = SocketUtils::AcceptClientConnection(serverSocket);

        if (clientSocket != -1) {
            std::cout << "Client connected. Creating a new thread to handle it.\n";

            std::thread clientThread(ClientThreadFunc, this, clientSocket);
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

void Server::ClientThreadFunc(Server* server, int clientSocket) {
    try {
        // Delegate the responsibility of handling the client to the assigned client handler
        server->clientHandler->Handle(clientSocket);
    } catch (const std::exception& e) {
        std::cerr << "Error handling client: " << e.what() << std::endl;
    }

    // Close the client socket
    SocketUtils::CloseSocket(clientSocket);
}
