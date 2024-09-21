#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    const char *fifo_path = "/tmp/my_fifo";
    char buffer[100];

    // Wait for the FIFO to be created by the writer
    while (access(fifo_path, F_OK) == -1) {
        printf("Waiting for FIFO to be created...\n");
        sleep(1);
    }

    // Open FIFO for reading
    int fd = open(fifo_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read the message from the FIFO
    ssize_t num_bytes = read(fd, buffer, sizeof(buffer) - 1);
    if (num_bytes == -1) {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Null-terminate the received string
    buffer[num_bytes] = '\0';

    // Print the received message
    printf("Received: %s", buffer);

    // Close the FIFO
    close(fd);

    // Remove the FIFO after reading
    unlink(fifo_path);

    return 0;
}
