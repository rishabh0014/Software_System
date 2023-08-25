#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char *path = getenv("PATH");
    
    if (path != NULL) {
        printf("PATH: %s\n", path);
    } else {
        printf("PATH environmental variable not found.\n");
    }

    return 0;
}
