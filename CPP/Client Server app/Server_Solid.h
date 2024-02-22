// Server.h
#pragma once

#include <vector>
#include <thread>

class ClientHandler {
public:
    virtual ~ClientHandler() {}
    virtual void Handle(int clientSocket) = 0;
};

class Server {
public:
    Server(int port, ClientHandler* handler);
    ~Server();

    void Start();
    void Stop();

private:
    int port;
    int serverSocket;
    std::vector<std::thread> clientThreads;
    ClientHandler* clientHandler;

    static void ClientThreadFunc(Server* server, int clientSocket);
};
