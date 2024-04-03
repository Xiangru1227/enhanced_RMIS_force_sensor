#pragma once
// TCPServer.h

#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <ws2tcpip.h>

class TCPServer {
public:
    TCPServer();
    bool initialize(PCSTR port);
private:
    SOCKET ListenSocket;
    SOCKET ClientSocket;
};

#endif // TCPSERVER_H
