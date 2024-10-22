/*
============================================================================
Name : 34b.c
Author : Shivam Pandey
Enrollment Number : MT2024145
Description :Write a program to create a concurrent server.
            b. use pthread_create.

output : Server listening on port 8080...
        Message from client: Hello from client!

============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *socket_desc) {
    int client_socket = *(int *)socket_desc;
    char buffer[BUFFER_SIZE] = {0};
    read(client_socket, buffer, BUFFER_SIZE);
    printf("Message from client: %s\n", buffer);
    const char *response = "Hello from pthread server!";
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
    free(socket_desc);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET; 
    address.sin_port = htons(PORT); 
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("Accept");
            continue;
        }
        int *new_sock = malloc(1);
        *new_sock = new_socket;

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_sock) < 0) {
            perror("Could not create thread");
            free(new_sock);
        }
    }

    close(server_fd);
    return 0;
}
