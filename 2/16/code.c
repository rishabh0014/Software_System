#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    int fd = open(filename, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Waitig for Lock\n");

    if (flock(fd, LOCK_EX) == -1) {
        perror("Error acquiring lock");
        close(fd);
        return 1;
    }
    printf("File locked. Press Enter to release the lock.\n");
    getchar(); 

    if (flock(fd, LOCK_UN) == -1) {
        perror("Error releasing lock");
        close(fd);
        return 1;
    }

    printf("File lock released.\n");

    close(fd);

    return 0;
}
