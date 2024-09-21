//Kunal Agarwal MT2024083
//21. Write two programs so that both can communicate by FIFO -Use two way communications.
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

    // Send message to receiver
    int fd = open(fifo_to_receiver, O_WRONLY);
    write(fd, "Hello from Sender!\n", 19);
    close(fd);

    // Wait for response
    char buffer[100];
    fd = open(fifo_to_sender, O_RDONLY);
    read(fd, buffer, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Received: %s", buffer);
    close(fd);

    unlink(fifo_to_receiver);
    unlink(fifo_to_sender);
    return 0;
}
