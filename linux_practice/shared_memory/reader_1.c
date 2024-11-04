#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = 5678; // Same key as the writer program

    // Access the existing shared memory segment
    int shm_id = shmget(key, 1024, 0666);
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

    // Read and print data from shared memory
    printf("Data read from shared memory: %s\n", shared_mem);

    // Detach from shared memory
    shmdt(shared_mem);

    // Mark the segment for deletion (only the reader program does this)
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}
