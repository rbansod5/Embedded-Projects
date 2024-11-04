#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 5

int main()
{
    int fd,new_fd;
    struct sockaddr_in address={0};
    char buffer[BUFFER_SIZE]={0};
    char *message="hello i am server";
    int addrlen=sizeof(address);

    address.sin_family=AF_INET;
    address.sin_addr.s_addr=INADDR_ANY;
    address.sin_port=htons(PORT);

    fd=socket(AF_INET,SOCK_STREAM,0);
    bind(fd,(struct sockaddr *)&address,addrlen);
    listen(fd,MAX_CONNECTIONS);
    new_fd=accept(fd,(struct sockaddr *)&address,(socklen_t *)&addrlen);

    while(1)
    {
    read(new_fd, buffer, BUFFER_SIZE);
    printf("Message from client: %s\n", buffer);

    send(new_fd, message, strlen(message), 0);
    printf("Hello message sent to client\n");
    }
}