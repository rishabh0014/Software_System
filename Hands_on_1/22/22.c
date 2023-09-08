/*
============================================================================
Name : 22.c
Author : Rishabh Teli
Description : 22. Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int fd = open("temp.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    
    if (fd == -1) {
        perror(":(");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror(":(");
        return 1;
    } else if (pid == 0) {
        char *by_child = "Hello from Child Process\n";
        write(fd, by_child, strlen(by_child));
    } else {
        char *by_parent = "Hello from Parent Process\n";
        write(fd, by_parent, strlen(by_parent));
        wait(NULL);
    }

    close(fd);
    return 0;
}