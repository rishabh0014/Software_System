#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *filename = "x.txt";
    const char *str = "Hello :) \n";

 
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    int fd_dup = dup(fd);

    write(fd, str, strlen(str));

    write(fd_dup, str, strlen(str));

    
    int fd_dup2 = dup2(fd, fd_dup);
    write(fd_dup, str, strlen(str));

    int fd_fcntl = fcntl(fd, F_DUPFD, 0);
    write(fd_fcntl, str, strlen(str));

    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    // Check the file's contents
    FILE *file = fopen(filename, "r");
    if (file) {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("File str: %s", buffer);
        }
        fclose(file);
    } else {
        perror(":(");
        return 1;
    }

    return 0;
}
