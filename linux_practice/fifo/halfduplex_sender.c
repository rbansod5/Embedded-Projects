#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    int fdr, fdw;
    char a[100], b[100];

    // Create FIFOs and check for errors
    if (mkfifo("fifohd1", 0600) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    if (mkfifo("fifohd2", 0600) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Open FIFOs for reading and writing
    fdr = open("fifohd1", O_RDWR);
    if (fdr == -1) {
        perror("open fdr");
        exit(EXIT_FAILURE);
    }

    fdw = open("fifohd2", O_RDWR);
    if (fdw == -1) {
        perror("open fdw");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("you: ");
        scanf("%[^\n]s", a);
        getchar(); // Consume newline character

        // Write message to fdw (fifohd2)
        if (write(fdw, a, strlen(a) + 1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Clear buffer and read from fdr (fifohd1)
        bzero(b, sizeof(b));
        if (read(fdr, b, sizeof(b)) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("from hyd: %s\n", b);
    }

    close(fdr);
    close(fdw);
    return 0;
}
