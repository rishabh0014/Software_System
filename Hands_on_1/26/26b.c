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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    printf("Entered string: %s\n", argv[1]);

    return 0;
}