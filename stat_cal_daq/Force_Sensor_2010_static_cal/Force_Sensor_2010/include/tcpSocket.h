#pragma once
#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")

class TCPSocket {

public:
    int iSendResult;
    int iResult;
    char msg[512];
    int msgbuflen = 512;
    WSAData wsa;
    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    bool initialize(PCSTR port_address);

    bool send_msg(char msg[7]);

    bool kill_server();
};

#endif // TCPSOCKET_H
