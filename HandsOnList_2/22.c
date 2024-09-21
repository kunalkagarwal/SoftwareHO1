//Kunal Agarwal MT2024083
/*22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <errno.h>

#define FIFO_PATH "/tmp/myfifo"

int main() {
    int fd;
    fd_set fds;
    struct timeval timeout = {10, 0};  // 10 seconds

    // Create FIFO
    if (mkfifo(FIFO_PATH, 0666) == -1 && errno != EEXIST) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Open FIFO for reading
    fd = open(FIFO_PATH, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Set up fd_set and call select
    FD_ZERO(&fds);
    FD_SET(fd, &fds);
    int result = select(fd + 1, &fds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select");
    } else if (result == 0) {
        printf("Timeout\n");
    } else {
        printf("Data available\n");
    }

    close(fd);
    unlink(FIFO_PATH);
    return 0;
}
