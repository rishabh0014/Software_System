/*
============================================================================
Name : 27.c
Author : Rishabh Teli
Description : 27. Write a program to execute ls -Rl by the following system calls
                a. execl
                b. execlp
                c. execle
                d. execv
                e. execvp
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return 1;
    } else if (child_pid == 0) {
        printf("Using fork and execl:\n");
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl"); 
        exit(1);
    }

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return 1;
    } else if (child_pid == 0) {
        printf("\nUsing fork and execlp:\n");
        execlp("/bin/ls", "ls", "-Rl", NULL);
        perror("execlp"); 
        exit(1);
    }

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return 1;
    } else if (child_pid == 0) {
        printf("\nUsing fork and execle:\n");
        char *envp[] = {NULL}; 
        execle("/bin/ls", "ls", "-Rl", NULL, envp);
        perror("execle"); 
        exit(1);
    }

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return 1;
    } else if (child_pid == 0) {
        printf("\nUsing fork and execv:\n");
        char *args[] = {"ls", "-Rl", NULL};
        execv("/bin/ls", args);
        perror("execv"); 
        exit(1);
    }

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return 1;
    } else if (child_pid == 0) {
        printf("\nUsing fork and execvp:\n");
        char *args[] = {"ls", "-Rl", NULL};
        execvp("ls", args);
        perror("execvp"); 
        exit(1);
    }

    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }

    return 0;
}