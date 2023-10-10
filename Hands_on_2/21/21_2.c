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

    fd1 = open("myfifo1", O_RDONLY);
    fd2 = open("myfifo2", O_WRONLY);

    read(fd1,buff1,sizeof(buff1));
    printf("Text from FIFO: %s\n",buff1);
    
    printf("Enter text: ");
    scanf("%[^\n]",buff2);
    write(fd2,buff2,sizeof(buff2));

    return 0;
}