/*
============================================================================
Name : 28.c
Author : Rishabh Teli
Description : 28. Write a program to get maximum and minimum real time priority.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main() {
    int min_priority, max_priority;

    min_priority = sched_get_priority_min(SCHED_FIFO);
    if (min_priority == -1) {
        perror("sched_get_priority_min");
        return 1;
    }

    max_priority = sched_get_priority_max(SCHED_FIFO);
    if (max_priority == -1) {
        perror("sched_get_priority_max");
        return 1;
    }

    printf("Minimum real-time priority: %d\n", min_priority);
    printf("Maximum real-time priority: %d\n", max_priority);

    return 0;
}