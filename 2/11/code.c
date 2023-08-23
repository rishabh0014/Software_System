#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *filename = "test_file.txt";
    const char *content = "Hello, World!\n";

    // Open the file for writing
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Duplicate the file descriptor using dup
    int fd_duplicate = dup(fd);

    // Append content using the original descriptor
    write(fd, content, strlen(content));

    // Append content using the duplicated descriptor
    write(fd_duplicate, content, strlen(content));

    // Use dup2 to duplicate the descriptor and update the duplicated one
    int fd_dup2 = dup2(fd, fd_duplicate);
    write(fd_duplicate, content, strlen(content));

    // Use fcntl to duplicate and update the descriptor
    int fd_fcntl = fcntl(fd, F_DUPFD, 0);
    write(fd_fcntl, content, strlen(content));

    // Close all descriptors
    close(fd);
    close(fd_duplicate);
    close(fd_dup2);
    close(fd_fcntl);

    // Check the file's contents
    FILE *file = fopen(filename, "r");
    if (file) {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("File content: %s", buffer);
        }
        fclose(file);
    } else {
        perror("Error opening file for reading");
        return 1;
    }

    return 0;
}
