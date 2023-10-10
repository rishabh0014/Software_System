/*
============================================================================
Name : 25.c
Author : Rishabh Teli
Description : 25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
                a. access permission
                b. uid, gid
                c. time of last message sent and received
                d. time of last change in the message queue
                d. size of the queue
                f. number of messages in the queue
                g. maximum number of bytes allowed
                h. pid of the msgsnd and msgrcv
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

int main()
{
    key_t key;
    int msqid;
    struct msqid_ds msq_info;

    key = ftok(".", 'R'); 

    if (key == -1)
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    msqid = msgget(key, IPC_CREAT | 0666);

    if (msqid == -1)
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    if (msgctl(msqid, IPC_STAT, &msq_info) == -1)
    {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    printf("Message Queue Information:\n");
    printf("Access Permission: %o\n", msq_info.msg_perm.mode);
    printf("UID: %d\n", msq_info.msg_perm.uid);
    printf("GID: %d\n", msq_info.msg_perm.gid);
    printf("Last Message Sent Time: %s", ctime(&msq_info.msg_stime));
    printf("Last Message Received Time: %s", ctime(&msq_info.msg_rtime));
    printf("Last Change Time: %s", ctime(&msq_info.msg_ctime));
    printf("Size of Queue: %ld bytes\n", msq_info.msg_qbytes);
    printf("Number of Messages in Queue: %ld\n", msq_info.msg_qnum);
    printf("Maximum Number of Bytes Allowed: %ld bytes\n", msq_info.msg_qbytes);
    printf("PID of Last msgsnd: %d\n", msq_info.msg_lspid);
    printf("PID of Last msgrcv: %d\n", msq_info.msg_lrpid);

    return 0;
}
