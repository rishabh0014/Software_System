/*
============================================================================
Name : 24.c
Author : Rishabh Teli
Description : 24. Write a program to create a message queue and print the key and message queue id.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    key_t key = ftok(".", 'R');
    int msgid = msgget(key,IPC_CREAT | IPC_EXCL | 0744);

    printf("key: %ox\t msgid: %d\n",key,msgid);
}