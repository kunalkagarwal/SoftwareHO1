//Kunal Agarwal MT2024083
/*24. Write a program to create an orphan process.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Create a new process

    if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // This is the child process
        printf("Child process (PID: %d) is running\n", getpid());

        // Make the child process sleep for a while to simulate work
        sleep(10);

        printf("Child process (PID: %d) is exiting\n", getpid());
        exit(EXIT_SUCCESS);
    } else {
        // This is the parent process
        printf("Parent process (PID: %d) is exiting\n", getpid());
        
        // Terminate the parent process
        exit(EXIT_SUCCESS);
    }

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 24.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
Parent process (PID: 90377) is exiting
Child process (PID: 90378) is running*/