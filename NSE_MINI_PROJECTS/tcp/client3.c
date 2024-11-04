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
    struct sockaddr_in address = {0};
    char buffer[BUFFER_SIZE] = {0};
    char *message = "hi, i am client";
    int addrlen = sizeof(address);
    char *ip_address="127.0.0.1";

    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &address.sin_addr);
    address.sin_port = htons(PORT);

    fd = socket(AF_INET, SOCK_STREAM, 0);
    connect(fd, (struct sockaddr *)&address, addrlen);

    char ch;
    while (1)
    {
        while ((ch = getchar()) != '\n')
        {
            send(fd, message, strlen(message), 0);

            read(fd, buffer, BUFFER_SIZE);
            printf("get data from server: %s\n", buffer);

            sleep(5);
        }
    }
}
