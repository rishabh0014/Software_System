/*
============================================================================
Name : 4.c
Author : Rishabh Teli
Description : 4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
	int fd;
	fd = open("example.txt", O_CREAT | O_EXCL);
	if (fd == -1) {
        perror("Error creating file");
        return 1;
	}
	return 0;
}