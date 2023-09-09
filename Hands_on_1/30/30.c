/*
============================================================================
Name : 30.c
Author : Rishabh Teli
Description : 30. Write a program to run a script at a specific time using a Daemon process.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<time.h>

int main(void)
{

    FILE*fp = fopen("x.txt","w");
	if(fork()==0){
		setsid();
		umask(0);
		chdir("/");
		while(1){
		    sleep(5);
			fprintf(fp,"Hello\n");
			fflush(fp);
	    }
	}else{
		exit(0);
	}
    return 0;
}