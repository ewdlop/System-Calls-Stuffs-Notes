// Client.cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

int main() {
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    SOCKET ConnectSocket = INVALID_SOCKET;
    ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET) {
        std::cerr << "Error at socket(): " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    clientService.sin_port = htons(54000);
    inet_pton(AF_INET, "127.0.0.1", &clientService.sin_addr);

    iResult = connect(ConnectSocket, (sockaddr*)&clientService, sizeof(clientService));
    if (iResult == SOCKET_ERROR) {
        std::cerr << "Unable to connect to server: " << WSAGetLastError() << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    char recvbuf[512];
    iResult = recv(ConnectSocket, recvbuf, 512, 0);
    if (iResult > 0) {
        std::cout << "Received: " << std::string(recvbuf, 0, iResult) << std::endl;
    } else if (iResult == 0) {
        std::cout << "Connection closed" << std::endl;
    } else {
        std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
    }

    closesocket(ConnectSocket);
    WSACleanup();
    return 0;
}
