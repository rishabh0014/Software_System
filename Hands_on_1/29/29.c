/*
============================================================================
Name : 29.c
Author : Rishabh Teli
Description : 29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
    int policy;
    struct sched_param params;

    int pid = getpid(); 
    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current scheduling policy: ");
    switch (policy) {
        case SCHED_OTHER:
            printf("SCHED_NORMAL\n");
            break;
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        default:
            printf("Unknown (%d)\n", policy);
            break;
    }

    params.sched_priority = 99; 
    if (sched_setscheduler(pid, SCHED_FIFO, &params) == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    printf("New scheduling policy: SCHED_FIFO\n");

    return 0;
}