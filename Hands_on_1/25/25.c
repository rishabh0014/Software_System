/*
============================================================================
Name : 25.c
Author : Rishabh Teli
Description : 25. Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pids[3];

    for (int i = 0; i < 3; ++i) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            printf("Child %d (PID %d) executing\n", i + 1, getpid());
            sleep(i + 1);
            printf("Child %d (PID %d) exiting\n", i + 1, getpid());
            exit(0);
        } else {
            child_pids[i] = pid;
        }
    }

    int status;
    pid_t second_child_pid = child_pids[1];
    printf("Parent process (PID %d) waiting for second child (PID %d)...\n", getpid(), second_child_pid);
    waitpid(second_child_pid, &status, 0);
    printf("Parent process (PID %d) finished waiting for second child (PID %d)\n", getpid(), second_child_pid);

    return 0;
}