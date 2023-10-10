/*
============================================================================
Name : 20.c
Author : Rishabh Teli
Description : 20. Write two programs so that both can communicate by FIFO -Use one way communication
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

    int fd;
    char buff[100];

    fd = open("myfifo", O_RDONLY);
    read(fd, buff, sizeof(buff));
     
    printf("Text form FIFO: %s\n",buff);
}