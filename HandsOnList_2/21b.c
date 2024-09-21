#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *fifo_to_receiver = "/tmp/fifo_to_receiver";
    const char *fifo_to_sender = "/tmp/fifo_to_sender";
    mkfifo(fifo_to_receiver, 0666);
    mkfifo(fifo_to_sender, 0666);

    // Receive message from sender
    char buffer[100];
    int fd = open(fifo_to_receiver, O_RDONLY);
    read(fd, buffer, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Received: %s", buffer);
    close(fd);

    // Send response to sender
    fd = open(fifo_to_sender, O_WRONLY);
    write(fd, "Hello from Receiver!\n", 21);
    close(fd);

    unlink(fifo_to_receiver);
    unlink(fifo_to_sender);
    return 0;
}
