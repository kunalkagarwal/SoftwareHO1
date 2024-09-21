#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

int main() {
    // Replace with your message queue ID
    key_t key = 1234; // Replace with your actual key
    int msgid;

    // Get the message queue ID
    msgid = msgget(key, 0666 | IPC_EXCL); // IPC_EXCL to ensure we get the exact queue if it exists

    if (msgid == -1) {
        if (errno == ENOENT) {
            // The message queue does not exist
            fprintf(stderr, "Message queue with key %d does not exist.\n", key);
        } else {
            // Error occurred
            perror("msgget");
        }
        return 1;
    }

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Message queue with key %d removed successfully.\n", key);
    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 29.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Message queue with key 1234 does not exist.*/