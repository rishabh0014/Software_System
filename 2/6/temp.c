#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
        char message[100];
        read(STDOUT_FILENO,message,100);
        write(STDOUT_FILENO,message,100);
        return 0;
}