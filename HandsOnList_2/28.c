//Kunal Agarwal MT2024083
// 28. Write a program to change the exiting message queue permission. (use msqid_ds structure)

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

int main() {
    key_t key = 1234; // Replace with your message queue key
    int msqid = msgget(key, 0); // Get message queue ID

    if (msqid == -1) {
        perror("msgget");
        return 1;
    }

    struct msqid_ds buf;
    if (msgctl(msqid, IPC_STAT, &buf) == -1) {
        perror("msgctl IPC_STAT");
        return 1;
    }

    buf.msg_perm.mode = S_IRUSR | S_IWUSR; // Set permissions to rw for owner

    if (msgctl(msqid, IPC_SET, &buf) == -1) {
        perror("msgctl IPC_SET");
        return 1;
    }

    printf("Message queue permissions updated successfully.\n");
    return 0;
}

/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 28.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Message queue permissions updated successfully.*/