/*27. Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

#define MSG_SIZE 100

struct msgbuf {
    long mtype;        // message type
    char mtext[MSG_SIZE]; // message text
};

int main() {
    key_t key = ftok("msgqueuefile", 65); // Generate a unique key
    int msgid = msgget(key, 0666 | IPC_CREAT); // Create or get the message queue
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    struct msgbuf message;

    // Receiving message with 0 as a flag
    if (msgrcv(msgid, &message, sizeof(message.mtext), 0, 0) == -1) {
        perror("msgrcv with flag 0 failed");
        exit(1);
    }
    printf("Received with flag 0: %s\n", message.mtext);

    // Receiving message with IPC_NOWAIT flag
    if (msgrcv(msgid, &message, sizeof(message.mtext), 0, IPC_NOWAIT) == -1) {
        perror("msgrcv with IPC_NOWAIT failed");
    } else {
        printf("Received with IPC_NOWAIT: %s\n", message.mtext);
    }

    // Cleanup
    msgctl(msgid, IPC_RMID, NULL); // Remove the message queue
    return 0;
}
