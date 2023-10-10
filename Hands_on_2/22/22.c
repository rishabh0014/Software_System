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

int main()
{
    mkfifo("myfifo", 0777);
    printf("FIFO file myfifo created successfully \n");

    return 0;
}