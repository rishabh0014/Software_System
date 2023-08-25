#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct flock fl = {F_WRLCK,SEEK_SET,0,0,0};
    const char *filename = argv[1];
    if(argv[2][0]=='r'){
        fl.l_type = F_RDLCK;
    }
    else if(argv[2][0]=='w'){
        fl.l_type = F_WRLCK;
    }
    else{
        perror("Invalid Operation :(");
        return 1;
    }

    int fd = open(filename, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Waitig for Lock\n");

    if (fcntl(fd,F_SETLKW,&fl) == -1) {
        perror("Error acquiring lock");
        close(fd);
        return 1;
    }
    printf("File locked. Press Enter to release the lock.\n");
    getchar(); 

    fl.l_type = F_UNLCK;;
    if (fcntl(fd,F_SETLKW,&fl) == -1) {
        perror("Error releasing lock");
        close(fd);
        return 1;
    }

    printf("File lock released.\n");

    close(fd);

    return 0;
}
