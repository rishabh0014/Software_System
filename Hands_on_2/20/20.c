/*
============================================================================
Name : 20.c
Author : Rishabh Teli
Description : 20. Write two programs so that both can communicate by FIFO -Use one way communication
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    mkfifo("myfifo", 0666);
    printf("FIFO file myfifo created successfully in the present directory.\n");

    return 0;
}
