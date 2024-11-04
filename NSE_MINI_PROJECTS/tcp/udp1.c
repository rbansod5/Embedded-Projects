#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int fd;
    char *message = "HI, I AM RAHUL";
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in server_address, client_address;
    socklen_t client_addrlen = sizeof(client_address);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    bind(fd, (const struct sockaddr *)&server_address, sizeof(server_address));

    while (1)
    {
        recvfrom(fd, buffer, BUFFER_SIZE, 0,
                 (struct sockaddr *)&client_address, &client_addrlen);
        printf("Received from client: %s\n", buffer);
        sendto(fd, message, strlen(message), 0,
               (const struct sockaddr *)&client_address, client_addrlen);
        sleep(5);
    }
    close(fd);
    return 0;
}
