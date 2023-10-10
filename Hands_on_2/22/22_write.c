/*
============================================================================
Name : 22.c
Author : Rishabh Teli
Description : 22. Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/select.h>

int main()
{
    char buff[100];
    int fd = open("myfifo", O_WRONLY);

    printf("Enter text: ");
    scanf("%[^\n]", buff);
    write(fd, buff, sizeof(buff));

    return 0;
}