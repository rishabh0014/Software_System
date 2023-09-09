/*
============================================================================
Name : 20.c
Author : Rishabh Teli
Description : 20. Find out the priority of your running program. Modify the priority with nice command.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <errno.h>

int main() {
    
    id_t pid = getpid(); 
    int priority = getpriority(PRIO_PROCESS, pid);

    if (priority == -1) {
        if(errno == EINVAL){
            perror("Invaild arguments");
        }
        else if(errno == EACCES){
            perror("Access Denied");
        }
        else if(errno == ESRCH){
            perror("No such Process");
        }
    }

    printf("Priority of the current process (PID %d) is %d\n", pid, priority);
    printf("Enter new Priority: ");
    int num;
    scanf("%d",&num);
    nice(num);
    priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1) {
        if(errno == EINVAL){
            perror("Invaild arguments");
        }
        else if(errno == EACCES){
            perror("Access Denied");
        }
        else if(errno == ESRCH){
            perror("No such Process");
        }
    }
    printf("Modified Priority of the current process (PID %d) is %d\n", pid, priority);

    return 0;
}
