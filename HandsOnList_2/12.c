//Kunal Agarwal MT2024083
/*12.Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child: PID = %d, Parent PID = %d\n", getpid(), getppid());

        // Send SIGKILL to the parent process
        printf("Child: Sending SIGKILL to parent...\n");
        kill(getppid(), SIGKILL);
        /*The child process prints its PID and parent PID using getpid() and getppid().
         It then sends the SIGKILL signal to the parent process using the kill() function with the parent's PID (getppid()).*/

        // After killing the parent, sleep to demonstrate being an orphan
        sleep(5);
        printf("Child: Now orphaned, adopted by init/launchd. New Parent PID = %d\n", getppid());
    } else {
        // Parent process
        // Sleep to give the child time to send the SIGKILL
        sleep(10);
        printf("Parent: This line should never be printed since the parent is killed.\n");
    }

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 12.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Child: PID = 30362, Parent PID = 30361
Child: Sending SIGKILL to parent...
zsh: killed     ./a.out
kunalagarwal@Kunals-MacBook-Air software handson2 % Child: Now orphaned, adopted by init/launchd. New Parent PID = 1*/
