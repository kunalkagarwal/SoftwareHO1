//Kunal Agarwal MT2024083
/*20. Write two programs so that both can communicate by FIFO -Use one way communication.*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *fifo_path = "/tmp/my_fifo";
    const char *message = "Hello through FIFO\n";

    // Create FIFO
    if (mkfifo(fifo_path, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Open FIFO for writing
    int fd = open(fifo_path, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write the message to the FIFO
    if (write(fd, message, 19) == -1) { // Write exactly 19 bytes (length of message)
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the FIFO
    close(fd);

    return 0;
}
