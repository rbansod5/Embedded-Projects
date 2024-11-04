/**
 * @file tcp.c
 * @author RAHUL SHRIDHAR BANSOD (rahulsamyak.bansod@gmail.com)
 * @brief  This Program is for Transfer Control Protocol
 * @version 0.1
 * @date 2024-10-11
 * @copyright Copyright (c) 2024
 * 
 */

#include "header.h"

#define PORT 8080

// Function to create a socket for server
int create_socket_server() {
    int server_fd;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    return server_fd;
}

// Function to create a socket for client
int create_socket_client() {
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to bind socket to the port
void bind_socket(int server_fd, struct sockaddr_in *address) {
    if (bind(server_fd, (struct sockaddr *)address, sizeof(*address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
}

// Function to listen for incoming connections
void listen_for_connections(int server_fd) {
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
}

// Function to accept an incoming connection
int accept_connection(int server_fd, struct sockaddr_in *address) {
    int addrlen = sizeof(*address);
    int new_socket;
    if ((new_socket = accept(server_fd, (struct sockaddr *)address, (socklen_t *)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    return new_socket;
}

// Function to set up the server, including creating socket, binding, listening, and accepting
int setup_server(struct sockaddr_in *address) {
    int server_fd = create_socket();
    bind_socket(server_fd, address);
    listen_for_connections(server_fd);
    return accept_connection(server_fd, address);
}

// Function to handle communication with the client
void handle_client(int new_socket) {
    char buffer[1024] = {0};
    char *message = "Hello from server";

    recv(new_socket, buffer, sizeof(buffer) - 1);
    printf("Client: %s\n", buffer);

    send(new_socket, message, strlen(message), 0);
    printf("Message sent to client\n");
}


void send_data(int sock, const char *message) {
    send(sock, message, strlen(message), 0);
    printf("Message sent to server\n");
}


void recv_data(int sock, char *buffer, size_t size) {
    recv(sock, buffer, size, 0);
}

int accept_connection(int server_fd, struct sockaddr_in *address) {
    int addrlen = sizeof(*address);
    int new_socket;
    if ((new_socket = accept(server_fd, (struct sockaddr *)address, (socklen_t *)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    return new_socket;
}

// Function to close a socket
void close_socket(int socket_fd) {
    close(socket_fd);
}

 
