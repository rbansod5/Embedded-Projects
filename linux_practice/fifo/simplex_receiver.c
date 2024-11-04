#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    const char *fifo_path = "/tmp/my_fifo"; // Path to FIFO
    int fd;
    char buffer[128];

    // Open the FIFO for reading
    fd = open(fifo_path, O_RDONLY);

    // Read the message from the FIFO
    read(fd, buffer, sizeof(buffer));

    printf("Message received from FIFO: %s\n", buffer);

    // Close the FIFO
    close(fd);
    // Remove the FIFO file
    unlink(fifo_path);

    return 0;
}
