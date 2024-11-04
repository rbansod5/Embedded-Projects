#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = 5678; // Unique key for shared memory

    // Create shared memory segment with read/write permissions
    int shm_id = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }

    // Attach to the shared memory segment
    char *shared_mem = (char *)shmat(shm_id, NULL, 0);
    if (shared_mem == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }

    // Write a message to shared memory
    strcpy(shared_mem, "Hello from the writer!");

    printf("Data written to shared memory: %s\n", shared_mem);

    // Detach from shared memory
    shmdt(shared_mem);

    return 0;
}
