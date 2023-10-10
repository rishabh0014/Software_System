/*
============================================================================
Name : 21.c
Author : Rishabh Teli
Description : 21. Write two programs so that both can communicate by FIFO -Use two way communications.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1, fd2;
    char buff1[100];
    char buff2[100];

    fd1 = open("myfifo1", O_WRONLY);
    fd2 = open("myfifo2", O_RDONLY);

    printf("Enter text: ");
    scanf("%[^\n]",buff1);
    
    write(fd1,buff1,sizeof(buff1));

    read(fd2,buff2,sizeof(buff2));
    printf("Text from FIFO: %s\n",buff2);


    return 0;
}