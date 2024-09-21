#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int i;
    char filename[20];
    for (i = 0; i < 5; i++) {
        snprintf(filename, sizeof(filename), "file_%d.txt", i + 1);
        int fd = open(filename, O_CREAT | O_WRONLY, 0644);
        if (fd == -1) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
    }

    while (1) {
        sleep(1);
    }

    return 0;
}
