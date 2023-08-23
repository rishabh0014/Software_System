#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>

int main() {
    const char *filename = "ticket_file.txt";

    int fd = open(filename, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Acquire a write lock on the file
    if (flock(fd, LOCK_EX) == -1) {
        perror("Error acquiring lock");
        close(fd);
        return 1;
    }

    // Read the current ticket number
    int ticket_number;
    read(fd, &ticket_number, sizeof(ticket_number));

    // Increment the ticket number
    ticket_number++;

    // Write the updated ticket number back to the file
    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket_number, sizeof(ticket_number));

    printf("Reserved ticket: %d\n", ticket_number);

    // Release the lock
    if (flock(fd, LOCK_UN) == -1) {
        perror("Error releasing lock");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}
