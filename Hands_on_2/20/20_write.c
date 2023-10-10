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
#include <sys/stat.h>

int main()
{
    int fd;
    char buff[100];

    fd = open("myfifo", O_WRONLY);

    printf("Enter the Text: ");
    scanf("%[^\n]", buff);

    write(fd,buff,sizeof(buff));
}