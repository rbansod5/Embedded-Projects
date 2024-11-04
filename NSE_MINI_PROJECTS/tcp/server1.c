#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    const char *message = "Hello from server";

    // Setup the address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP address
    address.sin_port = htons(PORT);       // Convert port to network byte order

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    listen(server_fd, MAX_CONNECTIONS);

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);

    while (1)
    {
        // Read data sent by the client
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Message from client: %s\n", buffer);

        // Send a response back to the client
        send(new_socket, message, strlen(message), 0);
        printf("Hello message sent to client\n");
    }
    // Close the socket
    close(new_socket);
    close(server_fd);
}

