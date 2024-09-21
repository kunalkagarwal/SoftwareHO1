//Kunal Agarwal MT2024083
/*17. Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid1, pid2;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    // Fork the first child to execute "ls -l"
    if ((pid1 = fork()) == -1) {
        perror("fork");
        return 1;
    }

    if (pid1 == 0) {
        // Child 1
        close(pipefd[0]);  // Close unused read end
        dup2(pipefd[1], STDOUT_FILENO);  // Redirect stdout to pipe
        close(pipefd[1]);  // Close the original pipe write end

        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        return 1;
    }

    // Fork the second child to execute "wc"
    if ((pid2 = fork()) == -1) {
        perror("fork");
        return 1;
    }

    if (pid2 == 0) {
        // Child 2
        close(pipefd[1]);  // Close unused write end
        dup2(pipefd[0], STDIN_FILENO);  // Redirect stdin from pipe
        close(pipefd[0]);  // Close the original pipe read end

        execlp("wc", "wc", NULL);
        perror("execlp");
        return 1;
    }

    // Parent
    close(pipefd[0]);
    close(pipefd[1]);

    wait(NULL);  // Wait for both children to terminate
    wait(NULL);

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 17.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
      17     146     947*/