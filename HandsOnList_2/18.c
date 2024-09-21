/*18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipe1[2], pipe2[2];

    // Create pipes
    pipe(pipe1); // For ls | grep
    pipe(pipe2); // For grep | wc

    // Fork for 'ls -l'
    if (fork() == 0) {
        dup2(pipe1[1], STDOUT_FILENO); // Redirect stdout to pipe1
        close(pipe1[0]); // Close unused read end
        execlp("ls", "ls", "-l", NULL); // Execute ls
        perror("execlp ls"); exit(1);
    }

    // Fork for 'grep ^d'
    if (fork() == 0) {
        dup2(pipe1[0], STDIN_FILENO);  // Redirect stdin from pipe1
        dup2(pipe2[1], STDOUT_FILENO); // Redirect stdout to pipe2
        close(pipe1[1]); // Close unused write end
        close(pipe2[0]); // Close unused read end
        execlp("grep", "grep", "^d", NULL); // Execute grep
        perror("execlp grep"); exit(1);
    }

    // Fork for 'wc -l'
    if (fork() == 0) {
        dup2(pipe2[0], STDIN_FILENO); // Redirect stdin from pipe2
        close(pipe1[0]); // Close unused ends
        close(pipe1[1]);
        close(pipe2[1]);
        execlp("wc", "wc", "-l", NULL); // Execute wc
        perror("execlp wc"); exit(1);
    }

    // Parent closes all pipes
    close(pipe1[0]); close(pipe1[1]);
    close(pipe2[0]); close(pipe2[1]);

    // Wait for all children
    for (int i = 0; i < 3; i++) wait(NULL);

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 18.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
      1*/