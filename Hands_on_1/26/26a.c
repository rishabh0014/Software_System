/*
============================================================================
Name : 26.c
Author : Rishabh Teli
Description : 26. Write a program to execute an executable program.
                a. use some executable program
                b. pass some input to an executable program. (for example execute an executable of $./a.out name)
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *program = "./temp.out"; 
    char *args[] = {program, "This string to be printed", NULL};  

    execvp(program, args);

    perror("execvp");
    return 1;
}