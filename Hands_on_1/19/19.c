/*
============================================================================
Name : 19.c
Author : Rishabh Teli
Description : 19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <sys/types.h>

static inline uint64_t rdtsc(){
    uint64_t tsc;
    asm volatile("rdtsc ": "=A" (tsc));
    return tsc;
}

int main() {

    uint64_t start,end;
    pid_t pid;

    start = rdtsc();
    pid = getpid();
    end = rdtsc();

    printf("Process ID: %d\n",pid);
    printf("Time taken by PID: %d: %lu CPU Cylces\n",pid,end-start);
    return 0;
}