//Kunal Agarwal MT2024083
/*25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key = ftok("/tmp", 65);  // Use an existing file for generating the key
    int msqid = msgget(key, 0666 | IPC_CREAT);  // Access or create the message queue

    if (msqid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    struct msqid_ds buf;
    if (msgctl(msqid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    // Print the required information
    printf("Access Permissions: %o\n", buf.msg_perm.mode & 0777);
    printf("UID: %d, GID: %d\n", buf.msg_perm.uid, buf.msg_perm.gid);
    printf("Last msg sent: %s", ctime(&buf.msg_stime));
    printf("Last msg received: %s", ctime(&buf.msg_rtime));
    printf("Last change: %s", ctime(&buf.msg_ctime));
    printf("Queue size (bytes): %ld\n", buf.msg_cbytes);
    printf("Messages in queue: %lu\n", buf.msg_qnum);
    printf("Max bytes allowed: %lu\n", buf.msg_qbytes);
    printf("Last msgsnd PID: %d, Last msgrcv PID: %d\n", buf.msg_lspid, buf.msg_lrpid);

    return 0;
}

/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 25.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Access Permissions: 666
UID: 501, GID: 20
Last msg sent: Thu Jan  1 05:30:00 1970
Last msg received: Thu Jan  1 05:30:00 1970
Last change: Thu Sep 19 22:45:19 2024
Queue size (bytes): 0
Messages in queue: 0
Max bytes allowed: 2048
Last msgsnd PID: 0, Last msgrcv PID: 0*/
