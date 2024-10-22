/*
============================================================================
Name : 34a.c
Author :Shivam Pandey
Enrollment Number : MT2024145
Description :Write a program to create a concurrent server.
            a. use fork

output : Server listening on port 8080...
        Message from client: Hello from client!

============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    read(client_socket, buffer, BUFFER_SIZE);
    printf("Message from client: %s\n", buffer);
    const char *response = "Hello from fork server!";
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 

    bind(server_fd, (struct sockaddr *)&address, sizeof(address)) ;
    listen(server_fd, 3);

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("Accept");
            continue;
        }
        if (fork() == 0) {
            close(server_fd);
            handle_client(new_socket);
            exit(0);
        }
        close(new_socket); 
        wait(NULL);
    }

    close(server_fd);
    return 0;
}
