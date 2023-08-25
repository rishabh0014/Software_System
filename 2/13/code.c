#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
   
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(0, &read_fds);

    
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    
    int result = select(1, &read_fds, NULL, NULL, &timeout);

    if (result == -1) {
        perror(":(");
        return 1;
    } else if (result == 0) {
        printf("Time Up!!\n");
        printf("No data available within 10 seconds.\n");
    } else {
        if (FD_ISSET(0, &read_fds)) {
            printf("Data is available within 10 seconds.\n");
        }
    }

    return 0;
}
