#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = creat("example.txt", 0644);

    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }

    printf("File created successfully with descriptor: %d\n", fd);
    close(fd);

    return 0;
}
