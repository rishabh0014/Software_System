#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int ticket;
    printf("Enter the ticket number: ");
    scanf("%d", &ticket);
    printf("Ticket number: %d\n", ticket);

    struct flock fl = { F_WRLCK, SEEK_SET,0,0,0};
    fl.l_pid = getpid();
    int fd = open("tickets.txt", O_WRONLY | O_CREAT, 0644);
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
    snprintf(buffer, sizeof(buffer), "%d\n", ticket);
    write(fd, buffer, strlen(buffer));
    
    printf("Press Enter!!!\n");
    getchar(); 
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