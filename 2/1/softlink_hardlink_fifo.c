#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    int v = symlink("copy.txt","copy_soft.txt");
    if(v<0){
        perror("Failed");
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

