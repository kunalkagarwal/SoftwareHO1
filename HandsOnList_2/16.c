//Kunal Agarwal MT2024083
/*Write a program to send and receive data from parent to child vice versa. Use two way
communication.*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd1[2];  // Pipe for parent to child
    int fd2[2];  // Pipe for child to parent
    pid_t pid;
    char parent_message[] = "Hello from parent!";
    char child_message[] = "Hello from child!";
    char buffer[100];

    // Create pipes
    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("pipe failed");
        exit(1);
    }
    
    // Fork the process
    if ((pid = fork()) == -1) {
        perror("fork failed");
        exit(1);
    }
    
    if (pid > 0) {  // Parent process
        close(fd1[0]);  // Close unused read end of fd1
        close(fd2[1]);  // Close unused write end of fd2

        // Send message to child
        write(fd1[1], parent_message, sizeof(parent_message));
        close(fd1[1]);  // Close write end after sending

        // Receive message from child
        read(fd2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        close(fd2[0]);  // Close read end
    } else {  // Child process
        close(fd1[1]);  // Close unused write end of fd1
        close(fd2[0]);  // Close unused read end of fd2

        // Receive message from parent
        read(fd1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        // Send message to parent
        write(fd2[1], child_message, sizeof(child_message));
        close(fd2[1]);  // Close write end after sending
        close(fd1[0]);  // Close read end
    }

    return 0;
}

/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 16.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Child received: Hello from parent!
Parent received: Hello from child!*/