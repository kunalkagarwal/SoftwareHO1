//Kunal Agarwal MT2024083
/*23. Write a program to print the maximum number of files can be opened within a process and
size of a pipe*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>

int main() {
    // Get and print the maximum number of open files
    long max_files = sysconf(_SC_OPEN_MAX);
    if (max_files == -1) {
        perror("sysconf");
    } else {
        printf("Maximum number of open files: %ld\n", max_files);
    }

    // Create a pipe to determine the size of the pipe buffer
    int pipefds[2];
    if (pipe(pipefds) == -1) {
        perror("pipe");
        return 1;
    }

    // Get the size of the pipe buffer
    long pipe_size = fpathconf(pipefds[0], _PC_PIPE_BUF);
    if (pipe_size == -1) {
        perror("fpathconf");
    } else {
        printf("Size of a pipe buffer: %ld bytes\n", pipe_size);
    }

    // Close the pipe file descriptors
    close(pipefds[0]);
    close(pipefds[1]);

    return 0;
}

/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 23.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Maximum number of open files: 1048575
Size of a pipe buffer: 512 bytes*/