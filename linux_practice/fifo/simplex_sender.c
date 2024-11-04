#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    const char *fifo_path = "/tmp/my_fifo";  // Path to FIFO
    int fd;
    char message[] = "Hello from the sender!";

    // Create the named FIFO (if it doesn't exist already)
    mkfifo(fifo_path, 0666);

    // Open the FIFO for writing
    fd = open(fifo_path, O_WRONLY);

    // Write the message to the FIFO
    write(fd, message, sizeof(message));

    printf("Message sent to FIFO: %s\n", message);

    // Close the FIFO
    close(fd);

    return 0;
}
