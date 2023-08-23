#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    // Set up the file descriptor set for stdin
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    // Set the timeout to 10 seconds
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    // Use select to wait for input on stdin
    int result = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("Error in select");
        return 1;
    } else if (result == 0) {
        printf("No data available within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            printf("Data is available within 10 seconds.\n");
            // You can read the data from stdin here if needed.
        }
    }

    return 0;
}
