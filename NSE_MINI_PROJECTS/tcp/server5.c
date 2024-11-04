#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio_ext.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTION 5
#define BUFFER_SIZE 1024

int main()
{
    int fd, new_fd;
    struct sockaddr_in address = {0};
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *message = "hi, i am server";

    // address info
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // create socket
    fd = socket(AF_INET, SOCK_STREAM, 0);

    // bind
    bind(fd, (struct sockaddr *)&address, addrlen);

    // listen
    listen(fd, MAX_CONNECTION);

    // acccept
    new_fd = accept(fd, (struct sockaddr *)&address, &addrlen);

    char ch;
    while (1)
    {
        printf("enter mode S or R\n");
        __fpurge(stdin);
        scanf("%c", &ch);
        if (ch == 'R' || ch == 'r')
        {

            read(new_fd, buffer, BUFFER_SIZE);
            printf("received from server= %s\n", buffer);
        }
        else if (ch == 'S' || ch == 's')
        {
            send(new_fd, message, strlen(message), 0);
            printf("client send to server\n");
        }
    }
    close(fd);
    close(new_fd);
}
