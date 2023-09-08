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
    char *program = "./dont_delete.out"; 
    char *args[] = {program, "Print me", NULL};  

    execvp(program, args);

    perror("execvp");
    return 1;
}