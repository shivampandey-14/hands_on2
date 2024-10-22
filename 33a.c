/*
============================================================================
Name : 33_server.c
Author : Shivam Pandey
Enrollment Number : MT2024145
Description :Write a program to communicate between two machines using socket.

output : Server listening on port 8080...
        Message from client: Hello from client!

============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client!";
    char buffer[BUFFER_SIZE] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 

    inet_pton(AF_INET, "1.1.1.117", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) ;

    send(sock, message, strlen(message), 0);
    printf("Message sent from client: %s\n", message);

    read(sock, buffer, BUFFER_SIZE);
    printf("Response from server: %s\n", buffer);

    close(sock);

    return 0;
}
