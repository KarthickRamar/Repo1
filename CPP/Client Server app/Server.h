// Server.h
#pragma once

class Server {
public:
    Server(int port);
    ~Server();

    void Start();
    void Stop();

private:
    int port;
    int serverSocket;

    void HandleClient(int clientSocket);
};
