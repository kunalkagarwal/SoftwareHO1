//Kunal Agarwal MT2024083
/*15. Write a simple program to send some data from parent to the child process.*/
 
/* we use pipe() for inter-process communication (IPC) to send data from a parent process to a child process. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd[2];
    pid_t pid;
    char message[] = "Hello from parent!";
    char buffer[100];
    
    // Create pipe
    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(1);
    }
    
    // Fork the process
    if ((pid = fork()) == -1) {
        perror("fork failed");
        exit(1);
    }
    
    if (pid > 0) {  // Parent process
        close(fd[0]);  // Close unused read end
        write(fd[1], message, sizeof(message));  // Send message to child
        close(fd[1]);  // Close write end
    } else {  // Child process
        close(fd[1]);  // Close unused write end
        read(fd[0], buffer, sizeof(buffer));  // Read message from parent
        printf("Child received: %s\n", buffer);  // Print received message
        close(fd[0]);  // Close read end
    }

    return 0;
}

/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 15.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Child received: Hello from parent!*/