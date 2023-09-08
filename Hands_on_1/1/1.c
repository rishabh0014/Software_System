/*
============================================================================
Name : 1.c
Author : Rishabh Teli
Description : Create the following types of a files using (i) shell command (ii) system call 
            a. soft link (symlink system call)
            b. hard link (link system call)
            c. FIFO (mkfifo Library Function or mknod system call)
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    int v = symlink("copy.txt","copy_soft.txt");
    if(v<0){
        perror(":(");
        return 1;
    }

    int f = link("copy.txt","copy_hard.txt");
    if(f<0){
        perror("Failed");
        return 1;
    }

    int e = mknod("fifo",S_IFIFO,0);
    if(e<0){
        perror("Failed");
    }
    return 0;
}