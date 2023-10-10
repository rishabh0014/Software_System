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
    fd_set read_fds;
    struct timeval tv;
    tv.tv_sec = 10;
    int fd = open("myfifo", O_RDONLY);
    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);

    if (!select(fd + 1, &read_fds, NULL, NULL, &tv))
    {
        printf("No data available within 10 Seconds\n");
    }
    else
    {
        printf("Data is available Now\n");
        read(fd,buff,sizeof(buff));
        printf("Text form FIFO: %s\n",buff);
    }

    return 0;
}