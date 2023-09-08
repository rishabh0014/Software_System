/*
============================================================================
Name : 23.c
Author : Rishabh Teli
Description : 23. Write a program to create a Zombie state of the running program.
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
        exit(0);
    } else {
        printf("Parent process (PID %d) created child process (PID %d)\n", getpid(), pid_child);
        sleep(10);
        printf("Parent process (PID %d) exiting\n", getpid());
    }

    return 0;
}