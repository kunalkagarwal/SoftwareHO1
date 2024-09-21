//Kunal Agarwal MT2024083
/*26. Write a program to send messages to the message queue. Check $ipcs -q*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define MSG_KEY 1234
#define MSG_TYPE 1

// Define the message structure
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    int msgid;
    struct msg_buffer message;

    // Create or get the message queue
    msgid = msgget(MSG_KEY, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Prepare the message
    message.msg_type = MSG_TYPE;
    snprintf(message.msg_text, sizeof(message.msg_text), "Hello, World!");

    // Send the message
    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Message sent: %s\n", message.msg_text);

    return 0;
}


/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 26.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Message sent: Hello, World!
kunalagarwal@Kunals-MacBook-Air software handson2 % ipcs -q
IPC status from <running system> as of Sat Sep 14 16:15:56 IST 2024
T     ID     KEY        MODE       OWNER    GROUP
Message Queues:
q  65536 0x6111d45b --rw-rw-rw- kunalagarwal    staff
q  65537 0x000004d2 --rw-rw-rw- kunalagarwal    staff*/