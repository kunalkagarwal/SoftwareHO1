//Kunal Agarwal MT2024083
// //Write a program to create three child processes. The parent should wait for a particular child (use
// waitpid system call).
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status;

    // Create the first child process
    if ((pid1 = fork()) == 0) {
        // Child process 1
        printf("Child 1 (PID: %d)\n", getpid());
        sleep(2);  // Simulate work
        exit(0);
    } else if (pid1 < 0) {
        perror("fork");
        exit(1);
    }

    // Create the second child process
    if ((pid2 = fork()) == 0) {
        // Child process 2
        printf("Child 2 (PID: %d)\n", getpid());
        sleep(4);  // Simulate work
        exit(0);
    } else if (pid2 < 0) {
        perror("fork");
        exit(1);
    }

    // Create the third child process
    if ((pid3 = fork()) == 0) {
        // Child process 3
        printf("Child 3 (PID: %d)\n", getpid());
        sleep(6);  // Simulate work
        exit(0);
    } else if (pid3 < 0) {
        perror("fork");
        exit(1);
    }

    // Parent process
    printf("Parent (PID: %d)\n", getpid());

    // Wait for the second child process to finish
    if (waitpid(pid2, &status, 0) > 0) {
        //pid_t waitpid(pid_t pid, int *status, int options);
        //The waitpid function,is used by a process to wait for state changes in a child process, such as its termination
        //pid: Specifies which child process to wait for
        //status: A pointer to an integer where the status information of the child process will be stored. This integer can be analyzed using macros provided by <sys/wait.h>.
        //options: Flags that modify the behavior of waitpid
       // WIFEXITED(status): Returns true if the child terminated normally.
       // WEXITSTATUS(status): Returns the exit status of the child if WIFEXITED(status) is true.
      // WIFSIGNALED(status): Returns true if the child was terminated by a signal.
     // WTERMSIG(status): Returns the signal number that caused the child to terminate if WIFSIGNALED(status) is true.
        if (WIFEXITED(status)) {
            printf("Child 2 exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child 2 killed by signal %d\n", WTERMSIG(status));
        }
    } else {
        perror("waitpid");
    }

    // Wait for the remaining child processes
    waitpid(pid1, &status, 0);
    waitpid(pid3, &status, 0);

    return 0;
}
/*Output:
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 25.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
Child 1 (PID: 90968)
Child 2 (PID: 90969)
Parent (PID: 90967)
Child 3 (PID: 90970)
Child 2 exited with status 0*/