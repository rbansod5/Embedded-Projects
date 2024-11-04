#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    const char *message = "Hello from client";

    // Setup the server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Create socket file descriptor
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Convert the IP address to binary form
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // Connect to the server
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    while (1)
    {
        // Send message to the server
        send(sock, message, strlen(message), 0);
        printf("Hello message sent to server\n");

        // Receive message from the server
        read(sock, buffer, BUFFER_SIZE);
        printf("Message from server: %s\n", buffer);
        sleep(1);
    }
    // Close the socket
    close(sock);

    return 0;
}
