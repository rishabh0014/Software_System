/*
============================================================================
Name : 10.c
Author : Rishabh Teli
Description : 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
            a. check the return value of lseek
            b. open the file with od and check the empty spaces in between the data.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd = open("x.txt", O_RDWR);

    if (fd == -1) {
        perror(":(");
        return 1;
    }

    char data1[] = "ABCDEFGHIJ";
    write(fd, data1, sizeof(data1) - 1); 

    
    off_t seek_offset = lseek(fd, 10, SEEK_CUR);
    printf("lseek return value: %ld\n", seek_offset);


    const char data2[] = "abcd4fghij";
    write(fd, data2, sizeof(data2) - 1); 

    close(fd);

    
    char temp[100];
    snprintf(temp, sizeof(temp), "od -c %s", "x.txt");
    system(temp);

    return 0;
}