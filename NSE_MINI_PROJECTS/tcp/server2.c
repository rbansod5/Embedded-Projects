#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 5

int main()
{

int fd,new_fd;
char buffer[BUFFER_SIZE]={0};
char *message="hi, i am server";

//get address info
struct sockaddr_in address;
int addrlen=sizeof(address);
address.sin_family=AF_INET;//ipv4
address.sin_addr.s_addr=INADDR_ANY;
address.sin_port=htons(PORT);

//create socket(1,1,1)

fd=socket(AF_INET,SOCK_STREAM,0);

bind(fd,(struct sockaddr *)&address,addrlen);

listen(fd,MAX_CONNECTIONS);

new_fd=accept(fd,(struct sockaddr *)&address,(socklen_t *)&addrlen);

while(1)
{
    // Read data sent by the client
        read(new_fd, buffer, BUFFER_SIZE);
        printf("Message from client: %s\n", buffer);

        // Send a response back to the client
        send(new_fd, message, strlen(message), 0);
        printf("Hello message sent to client\n");
}

}