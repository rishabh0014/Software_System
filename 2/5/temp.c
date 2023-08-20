#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int i;
    for (i = 1; i <= 5; i++) {
        char filename[20];
        snprintf(filename, sizeof(filename), "file%d.txt", i);
        
        int fd = open(filename, O_CREAT | O_WRONLY, 0644);
        if (fd == -1) {
            perror("Error creating file");
            exit(EXIT_FAILURE);
        }
        close(fd);
    }
    while (1) {
        
    }
    
    return 0;
}
