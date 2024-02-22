#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define APP_MAX_BUFFER 1024
#define PORT 8080

int main() {

    WSADATA wsaData;
    SOCKET sockfd, server_fd, client_fd;

    struct sockaddr_in serverAddr;
    int address_len = sizeof(serverAddr);

    /*
        No buffer é onde irá ocorrer a cópia dos dados do Kernerl d Receiver do sistema operaconal.
        Essa operação de copia é por conexão.
    */
    char buffer[APP_MAX_BUFFER] = {0};

    // inicia o Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Erro ao inicializar o Winsock.\n");
        return 1;
    }

    // Cria o socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Erro ao criar o socket.\n");
        WSACleanup();
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    server_fd = sockfd;
    client_fd = accept(server_fd, NULL, NULL);

    if(bind(server_fd, (struct sockaddr *)&address_len, sizeof(address_len)) < 0) {
        perror("Bind failed!");
        exit(EXIT_FAILURE);
    }

    if(listen(server_fd, 10) < 0) {
        perror("Listen failed!");
        exit(EXIT_FAILURE);
    }

    while(1){
        printf("\nWaiting for connection!...\n");
        
        if((client_fd = accept(server_fd, (struct sockaddr *)&address_len, (socklen_t*)&address_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        read(client_fd, buffer, APP_MAX_BUFFER);
        printf("%s\n", buffer);
    
        char *http_response = "HTTP/1.1 200 ok\n"
                    "Content-Type: text/plain\n"
                    "Content-Length: 13\n\n"
                    "Hello World!\n";

        write(client_fd, http_response, strlen(http_response));

        closesocket(client_fd);
        WSACleanup();
    }

    return 0;

}
