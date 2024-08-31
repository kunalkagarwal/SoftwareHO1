//Kunal Agarwal MT2024083
// Write a program to create a Zombie state of the running program.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid > 0) {
        // Parent process: Do nothing and sleep
        printf("Parent process (PID: %d) sleeping. Child process (PID: %d) will become a zombie.\n", getpid(),  pid);
        sleep(30);  // Parent sleeps for 30 seconds
    } else {
        // Child process: Exit immediately
        printf("Child process (PID: %d) exiting.\n", getpid()) ;
        //the getpid() returns the pid of the current process.
        exit(0);
    }

    return 0;
}

/*
Output:
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 23.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
Parent process (PID: 89993) sleeping. Child process (PID: 89996) will become a zombie.
Child process (PID: 89996) exiting.
*/