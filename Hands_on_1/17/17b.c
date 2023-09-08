/*
============================================================================
Name : 17b.c
Author : Rishabh Teli
Description : 17. Write a program to simulate online ticket reservation. Implement write lock Write a program to open a file, store a ticket number and exit. Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {

    struct flock fl = { F_WRLCK, SEEK_SET,0,0,0};
    fl.l_pid = getpid();

    int fd = open("tickets.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("Waiting for Lock!!\n");

    if (fcntl(fd, F_SETLKW, &fl) == -1){
        perror(":(");
        exit(1);
    }

    char buffer[20];
    int bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead <= 0) {
        perror("Error reading from file");
        close(fd);
        return 1;
    }

    int currentTicket = atoi(buffer);

    printf("Current ticket number: %d\n", currentTicket);

    lseek(fd, 0, SEEK_SET);
    snprintf(buffer, sizeof(buffer), "%d\n", currentTicket + 1);
    write(fd, buffer, strlen(buffer));

    printf("Press Enter!!!\n");
    
    getchar(); 
    fl.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &fl) == -1) {
        perror("fcntl");
        exit(1);
    }

    printf("Lock Released :)\n");

    close(fd);

    return 0;
}
