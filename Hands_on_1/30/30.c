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

    struct tm exectime;
    exectime.tm_hour = 1;
	exectime.tm_min = 25;
	
	if(fork()==0){
		setsid();
		umask(0);
		chdir("/");
		while(1){
		    time_t timevalue = time(NULL);
		    struct tm* currtime = localtime(&timevalue);

		    if(currtime->tm_hour == exectime.tm_hour && currtime->tm_min == exectime.tm_min){

                int result = system("/home/rishabh/Desktop/IIITB/Software_System/Software_System/Hands_on_1/30/temp.sh");
                if (result == -1) {
                    perror("system");
                }
                return 0;
                break;
		    }
	    }
	}else{
		exit(0);
	}
    return 0;
}