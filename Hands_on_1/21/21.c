/*
============================================================================
Name : 21.c
Author : Rishabh Teli
Description : 21. Write a program, call fork and print the parent and child process id.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

    pid_t pid = fork();

    if(pid==-1){
        perror("fork");
    }
    else if(pid == 0){
        printf("Child Process: PID: %d\n",getpid());
    }
    else{
        printf("Parent Process: PID: %d\n",getpid());
        printf("Child process: PID: %d\n",getpid());
    }

    return  0;
}
