/*
============================================================================
Name : 14.c
Author : Rishabh Teli
Description : 14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    int fd[2];
    char buf[80];
    pipe(fd);
    write(fd[1], "Hello", 6);
    read(fd[0], buf,sizeof(buf));
    printf("From pipe: %s\n", buf);
}
