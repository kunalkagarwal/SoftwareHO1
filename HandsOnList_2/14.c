//Kunal Agarwal MT2024083
/*14.Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipe_fd[2];  // File descriptors for the pipe
    char write_msg[] = "Hello, pipe!";
    char read_msg[100];
    
    // Create the pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe failed");
        exit(1);
    }
    
    // Write to the pipe
    write(pipe_fd[1], write_msg, strlen(write_msg) + 1);
    
    // Read from the pipe
    read(pipe_fd[0], read_msg, sizeof(read_msg));
    
    // Display the result
    printf("Message read from pipe: %s\n", read_msg);
    
    // Close the pipe ends
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    return 0;
}

/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 14.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Message read from pipe: Hello, pipe!*/