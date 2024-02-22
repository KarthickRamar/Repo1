// ClientHandler.h
#pragma once

class ClientHandler {
public:
    virtual ~ClientHandler() {}
    virtual void Handle(int clientSocket) = 0;
};
