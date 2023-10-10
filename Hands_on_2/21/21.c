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
    mkfifo("myfifo1", 0777);
    mkfifo("myfifo2", 0777);
    printf("FIFO file myfifo1 and myfifo2 created successfully \n");

    return 0;
}