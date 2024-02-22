// Server.h
#pragma once

#include <vector>
#include <thread>

class Server {
public:
    Server(int port);
    ~Server();

    void Start();
    void Stop();

private:
    int port;
    int serverSocket;
    std::vector<std::thread> clientThreads;

    void HandleClient(int clientSocket);
};
