//Kunal Agarwal MT2024083
/*24. Write a program to create a message queue and print the key and message queue id.*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    // Generate a unique key for the message queue
    key = ftok("/tmp", 'a'); // Use a temporary file and a character for the key
    if (key == -1) {
        perror("ftok failed");
        exit(EXIT_FAILURE);
    }

    // Create a message queue with the generated key
    msgid = msgget(key, IPC_CREAT | 0666); // IPC_CREAT creates the queue if it doesn't exist, 0666 is the permission
    if (msgid == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    // Print the key and the message queue ID
    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}


/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 24.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Message Queue Key: 1628558427
Message Queue ID: 65536*/