//Kunal Agarwal MT2024083
/*21. Write a program, call fork and print the parent and child process id.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For fork()

int main() {
    pid_t pid;
    //pid_t is a data type used to represent process IDs.
    //the pid_t type is used with system calls like fork(), wait(), and getpid() to handle process identifiers.
    // Create a child process
    pid = fork();
    //The fork() system call creates a new process by duplicating the calling process. 
    // In the Parent Process:fork() returns the PID (Process ID) of the child process
    // In the Child Process:fork() returns 0.
    //If fork() fails (e.g., due to system limits on processes), it returns a negative value -1. This indicates an error occurred, and no child process is created.
    if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // This block is executed by the child process
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        // This block is executed by the parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }
    //The getpid() function returns the PID of the current process, and getppid() returns the PID of the parent process.


    return 0;
}
/*
Output:
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 21.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
Parent process: PID = 88757, Child PID = 88758
Child process: PID = 88758, Parent PID = 88757*/