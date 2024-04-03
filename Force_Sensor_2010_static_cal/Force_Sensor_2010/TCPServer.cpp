// TCPServer.cpp

#include "TCPServer.h"
#include <iostream>
#include <string>

// 由于使用Winsock，需要链接到Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")

TCPServer::TCPServer() : ListenSocket(INVALID_SOCKET), ClientSocket(INVALID_SOCKET) {}

bool TCPServer::initialize(PCSTR port) {
    WSADATA wsaData;
    int iResult;

    // 初始化Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cout << "WSAStartup failed with error: " << iResult << std::endl;
        return false;
    }

    struct addrinfo* result = nullptr, hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // 流式socket，TCP
    hints.ai_protocol = IPPROTO_TCP; // TCP协议
    hints.ai_flags = AI_PASSIVE; // 用于bind操作的socket地址

    // 解析本地地址和端口
    iResult = getaddrinfo(NULL, port, &hints, &result);
    if (iResult != 0) {
        std::cout << "getaddrinfo failed with error: " << iResult << std::endl;
        WSACleanup();
        return false;
    }

    // 创建监听socket
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        std::cout << "socket failed with error: " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        WSACleanup();
        return false;
    }

    // 绑定监听socket
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        std::cout << "bind failed with error: " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return false;
    }

    freeaddrinfo(result);

    // 监听连接
    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        std::cout << "listen failed with error: " << WSAGetLastError() << std::endl;
        closesocket(ListenSocket);
        WSACleanup();
        return false;
    }

    std::cout << "Server is listening on port " << port << std::endl;

    // 接受客户端连接
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        std::cout << "accept failed with error: " << WSAGetLastError() << std::endl;
        closesocket(ListenSocket);
        WSACleanup();
        return false;
    }

    std::cout << "Client connected." << std::endl;

    // 发送消息给客户端
    const char* sendbuf = "Server connected.\r\n";
    iResult = send(ClientSocket, sendbuf, (int)strlen(sendbuf), 0);
    if (iResult == SOCKET_ERROR) {
        std::cout << "send failed with error: " << WSAGetLastError() << std::endl;
        closesocket(ClientSocket);
        WSACleanup();
        return false;
    }

    // 关闭客户端socket
    closesocket(ClientSocket);
    // 关闭监听socket，终止服务器运行
    closesocket(ListenSocket);
    // 清理Winsock
    WSACleanup();

    return true;
}
