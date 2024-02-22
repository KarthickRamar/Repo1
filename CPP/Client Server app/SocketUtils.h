// SocketUtils.h
#pragma once

#include <string>

class SocketUtils {
public:
    static int CreateServerSocket(int port);
    static int AcceptClientConnection(int serverSocket);
    static int CreateClientSocket(const char* serverAddress, int port);
    static void SendData(int socket, const char* data);
    static std::string ReceiveData(int socket);
    static void CloseSocket(int socket);
};
