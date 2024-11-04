#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER 1024

int main()
{
    int fd;
    char buffer[MAX_BUFFER] = {0};
    char *message = "hi, i am client";
    struct sockaddr_in address = {0};
    int addrlen = sizeof(address);

    address.sin_family = AF_INET;
    inet_pton(INADDR_ANY, "127.0.0.1", &address.sin_addr);
    address.sin_port = htons(PORT);

    fd = socket(AF_INET, SOCK_STREAM, 0);
    connect(fd, (struct sockaddr *)&address, addrlen);

    char ch;
    while (1)
    {
        printf("enter mode S or R\n");
        __fpurge(stdin);
        scanf("%c", &ch);
        if (ch == 'R' || ch == 'r')
        {

            read(fd, buffer, MAX_BUFFER);
            printf("received from server= %s\n", buffer);
        }
        else if (ch == 'S' || ch == 's')
        {
            send(fd, message, strlen(message), 0);
            printf("client send to server\n");
        }
    }

    close(fd);
}
