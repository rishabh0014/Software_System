/*
============================================================================
Name : 7.c
Author : Rishabh Teli
Description : 7. Write a program to copy file1 into file2 ($cp file1 file2).
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char*argv[]){

    if(argc!=3){
        printf(":(");
        return 0;
    }
    // printf("%d",argc);
    // printf("%s",argv[0]);

    int fd_read = open(argv[1],O_RDONLY);
    int fd_write = open(argv[2],O_WRONLY | O_CREAT);

    if(fd_write == -1 || fd_read == -1){
        printf(":(");
    }

    while(1){
        char buf;
        int char_read = read(fd_read,&buf,1);
        if(!char_read) break;
        int char_write = write(fd_write,&buf,1);
    }

    int fd_read_close = close(fd_read);
    int fd_write_close = close(fd_write);
    if(fd_write_close == -1 || fd_read_close == -1){
        printf(":(");
    }
    return 0;
}