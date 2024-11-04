#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    const char *name = "/my_shm";
    int shm_fd = shm_open(name, O_RDONLY, 0666);
    void *ptr = mmap(0, 1024, PROT_READ, MAP_SHARED, shm_fd, 0);

    printf("Data read from shared memory: %s\n", (char *)ptr);

    shm_unlink(name);  // Remove shared memory object
    return 0;
}
