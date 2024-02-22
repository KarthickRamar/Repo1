// Client.h
#pragma once

class Client {
public:
    Client(const char* serverAddress, int port);
    ~Client();

    void Connect();
    void Disconnect();

    void SendMessage(const char* message);

private:
    const char* serverAddress;
    int port;
    int clientSocket;
};
