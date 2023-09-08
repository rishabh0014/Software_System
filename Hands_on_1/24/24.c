/*
============================================================================
Name : 24.c
Author : Rishabh Teli
Description : 24. Write a program to create an orphan process.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid_child = fork();

    if (pid_child == -1) {
        perror("fork");
        return 1;
    } else if (pid_child == 0) {
        printf("Child process (PID %d) executing\n", getpid());
        sleep(10);
        printf("Child process (PID %d) exiting\n", getpid());
    } else {
        printf("Parent process (PID %d) created child process (PID %d)\n", getpid(), pid_child);
        printf("Parent process (PID %d) exiting\n", getpid());
    }

    return 0;
}