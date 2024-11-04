#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>   // POSIX message queue header
#include <fcntl.h>    // O_* constants
#include <sys/stat.h> // mode constants

int main() {
    mqd_t mq;
    char message[] = "Hello from the sender!";
    struct mq_attr attr;

    // Message queue attributes
    attr.mq_flags = 0;        // Blocking mode
    attr.mq_maxmsg = 10;      // Maximum number of messages in the queue
    attr.mq_msgsize = 256;    // Maximum message size
    attr.mq_curmsgs = 0;      // Number of messages currently in the queue

    // Create a message queue
    mq = mq_open("/test_queue", O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }

    // Send a message
    if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
        perror("mq_send");
        exit(1);
    }

    printf("Message sent: %s\n", message);

    // Close the message queue
    mq_close(mq);
    return 0;
}
