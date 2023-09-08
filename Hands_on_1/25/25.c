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
    pid_t pid1,pid2,pid3;

    pid1 = fork();
    if(pid1==0){
        printf("Child 1 => pid = %d\n",getpid());
        exit(0);
    }

    pid2 = fork();
    if(pid2==0){
        printf("Child 2 => pid = %d\n",getpid());
        exit(0);
    }

    pid3 = fork();
    if(pid3==0){
        printf("Child 3 => pid = %d\n",getpid());
        exit(0);
    }
    int status;
    pid_t first_child_pid = waitpid(pid1, &status, 0);
    if(first_child_pid == pid1){
        printf("Parent: Child 1 with pid %d terminated\n",pid1);
    }
    printf("Parent : All processes terminated\n");
    return 0;
}