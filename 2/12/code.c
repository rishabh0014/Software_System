#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf(":(");
        return 0;
    }

    // Open the file
    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Use fcntl to get the file opening mode (flags)
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("Error getting file flags");
        close(fd);
        return 1;
    }

    // Check the file opening mode
    if (flags & O_RDONLY)
        printf("%s is opened in read-only mode.\n", file);
    else if (flags & O_WRONLY)
        printf("%s is opened in write-only mode.\n", file);
    else if (flags & O_RDWR)
        printf("%s is opened in read-write mode.\n", file);
    else
        printf("%s is opened in an unknown mode.\n", file);

    // Close the file
    close(fd);

    return 0;
}
