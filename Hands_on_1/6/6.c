/*
============================================================================
Name : 6.c
Author : Rishabh Teli
Description : 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
============================================================================
*/
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