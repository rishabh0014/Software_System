#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char* path = "test_file.txt";
    int file = open(path, O_RDWR);

    if (file == -1) {
        perror(":(");
        return 1;
    }

    char data1[] = "ABCDEFGHIJ";
    write(file, data1, sizeof(data1) - 1); 

    
    off_t seek_offset = lseek(file, 10, SEEK_CUR);
    printf("lseek return value: %ld\n", seek_offset);


    const char data2[] = "abc4efghij";
    write(file, data2, sizeof(data2) - 1); 

    close(file);

    
    char od_command[100];
    snprintf(od_command, sizeof(od_command), "od -c %s", path);
    system(od_command);

    return 0;
}