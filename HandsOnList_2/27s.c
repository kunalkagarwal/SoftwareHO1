#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

#define MSG_SIZE 100

struct msgbuf {
    long mtype;        // Message type
    char mtext[MSG_SIZE]; // Message text
};

int main() {
    key_t key = ftok("msgqueuefile", 65); // Unique key
    int msgid = msgget(key, 0666 | IPC_CREAT); // Create/get message queue
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    struct msgbuf message;
    message.mtype = 1; // Set message type

    // Prepare a message to send
    printf("Enter message: ");
    fgets(message.mtext, MSG_SIZE, stdin);
    message.mtext[strcspn(message.mtext, "\n")] = 0; // Remove newline

    // Send the message
    if (msgsnd(msgid, &message, sizeof(message.mtext), 0) == -1) {
        perror("msgsnd failed");
        exit(1);
    }

    printf("Message sent: %s\n", message.mtext);
    return 0;
}
