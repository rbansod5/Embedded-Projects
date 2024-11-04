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
    int fd, new_fd;
    char *message = "HI, I AM RAHUL";
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in address = {0};
    int addrlen = sizeof(address);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    fd = socket(AF_INET, SOCK_STREAM, 0);
    bind(fd, (struct sockaddr *)&address, addrlen);
    listen(fd, MAX_CONNECTIONS);
    new_fd = accept(fd, (struct sockaddr *)&address, &addrlen);
    
    while (1)
    {
        read(new_fd, buffer, BUFFER_SIZE);
        printf("received from client %s\n", buffer);
        sleep(5);
        send(new_fd, message, strlen(message), 0);
        
    }
}
