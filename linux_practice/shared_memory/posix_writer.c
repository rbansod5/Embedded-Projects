#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    const char *name = "/my_shm";
    int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, 1024);
    void *ptr = mmap(0, 1024, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // Write to shared memory
    sprintf(ptr, "Hello from POSIX shared memory!");
    return 0;
}
