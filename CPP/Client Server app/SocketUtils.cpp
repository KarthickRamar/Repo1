// SocketUtils.cpp
#include "SocketUtils.h"

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int SocketUtils::CreateServerSocket(int port) {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating server socket." << std::endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error binding server socket." << std::endl;
        CloseSocket(serverSocket);
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, SOMAXCONN) == -1) {
        std::cerr << "Error listening for connections." << std::endl;
        CloseSocket(serverSocket);
        exit(EXIT_FAILURE);
    }

    return serverSocket;
}

int SocketUtils::AcceptClientConnection(int serverSocket) {
    struct sockaddr_in clientAddress;
    socklen_t clientAddressSize = sizeof(clientAddress);
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressSize);

    if (clientSocket == -1) {
        std::cerr << "Error accepting client connection." << std::endl;
        return -1;
    }

    return clientSocket;
}

int SocketUtils::CreateClientSocket(const char* serverAddress, int port) {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating client socket." << std::endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    if (inet_pton(AF_INET, serverAddress, &(serverAddr.sin_addr)) <= 0) {
        std::cerr << "Invalid server address." << std::endl;
        CloseSocket(clientSocket);
        exit(EXIT_FAILURE);
    }

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error connecting to the server." << std::endl;
        CloseSocket(clientSocket);
        exit(EXIT_FAILURE);
    }

    return clientSocket;
}

void SocketUtils::SendData(int socket, const char* data) {
    ssize_t bytesSent = send(socket, data, strlen(data), 0);
    if (bytesSent == -1) {
        std::cerr << "Error sending data." << std::endl;
        CloseSocket(socket);
        exit(EXIT_FAILURE);
    }
}

std::string SocketUtils::ReceiveData(int socket) {
    char buffer[1024];
    ssize_t bytesRead = recv(socket, buffer, sizeof(buffer), 0);

    if (bytesRead == -1) {
        std::cerr << "Error receiving data." << std::endl;
        CloseSocket(socket);
        exit(EXIT_FAILURE);
    }

    return std::string(buffer, bytesRead);
}

void SocketUtils::CloseSocket(int socket) {
    close(socket);
}
