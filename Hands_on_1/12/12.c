/*
============================================================================
Name : 12.c
Author : Rishabh Teli
Description : 12. Write a program to find out the opening mode of a file. Use fcntl.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf(":(");
        return 0;
    }

    const char *file = argv[1];

    int fd = open(file, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("Error getting file flags");
        close(fd);
        return 1;
    }

    if (flags & O_RDONLY)
        printf("%s is opened in read-only mode.\n", file);
    else if (flags & O_WRONLY)
        printf("%s is opened in write-only mode.\n", file);
    else if (flags & O_RDWR)
        printf("%s is opened in read-write mode.\n", file);
    else
        printf("%s is opened in an unknown mode.\n", file);

    close(fd);

    return 0;
}
