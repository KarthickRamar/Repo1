// ConcreteHandler.h
#pragma once

#include "ClientHandler_Solid.h"

class ConcreteHandler : public ClientHandler {
public:
    void Handle(int clientSocket) override;
};
