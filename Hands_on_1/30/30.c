/*
============================================================================
Name : 30.c
Author : Rishabh Teli
Description : 30. Write a program to run a script at a specific time using a Daemon process.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    const int desired_hour = 13;  
    const int desired_minute = 38; 

    while (1) {
        time_t current_time;
        struct tm *timeinfo;

        time(&current_time);
        timeinfo = localtime(&current_time);
        if (timeinfo->tm_hour == desired_hour && timeinfo->tm_min == desired_minute) {
            int result = system("./temp.sh");
            if (result == -1) {
                perror("system");
            }
            return 0;
        }
        sleep(30);
    }

    return 0;
}