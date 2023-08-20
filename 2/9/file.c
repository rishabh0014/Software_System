#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main() {
    char *file = "x.txt";
    struct stat stat_;

    if(stat(file,&stat_)== -1){
        printf(":(");
        return 0;
    }

    printf("File: %s\n",file);
    printf("Inode: %lu\n", stat_.st_ino);
    printf("#Hard Links: %lu\n", stat_.st_nlink);
    printf("UID: %u\n",stat_.st_uid);
    printf("GID: %u\n",stat_.st_gid);
    printf("Size: %ld (Bytes)\n",stat_.st_size);
    printf("Block Size: %ld (Bytes)\n",stat_.st_blksize);
    printf("Number of Blocks: %ld\n",stat_.st_blocks);
    printf("Time of Last Access: %s\n", stat_.st_atime);
    printf("Time of Last Modificataion: %s\n" stat_.st_mtime);
    printf("Time of Last Change: %s\n", stat_.st_ctime);

    return 0;
}
