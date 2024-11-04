#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>   // POSIX message queue header
#include <fcntl.h>    // O_* constants
#include <sys/stat.h> // mode constants

int main() {
    mqd_t mq;
    char buffer[256];
    struct mq_attr attr;

    // Open the message queue
    mq = mq_open("/test_queue", O_RDONLY);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }

    // Receive a message
    if (mq_receive(mq, buffer, sizeof(buffer), NULL) == -1) {
        perror("mq_receive");
        exit(1);
    }

    printf("Message received: %s\n", buffer);

    // Close and unlink the message queue
    mq_close(mq);
    mq_unlink("/test_queue"); // Remove the queue
    return 0;
}
