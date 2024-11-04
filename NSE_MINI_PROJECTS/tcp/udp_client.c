#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
int main(int argc, char **argv)
{
    int fd;
    char buffer[BUFFER_SIZE] = {0}, *ipaddress = argv[1],*message="hi i am pankaj";
    struct sockaddr_in address;
    int addrlen = sizeof(address);
 
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ipaddress, &address.sin_addr);
    address.sin_port = htons(PORT);

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    connect(fd, (struct sockaddr *)&address, addrlen);

    while (1)
    {
        sendto(fd, message, strlen(message), 0,
               (struct sockaddr *)&address, addrlen);
        recvfrom(fd, buffer, BUFFER_SIZE, 0,
                 (struct sockaddr *)&address, &addrlen);
        printf("Received from server: %s\n", buffer);
    }
}
