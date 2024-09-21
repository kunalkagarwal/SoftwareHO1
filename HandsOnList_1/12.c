//Kunal Agarwal MT2024083
/*12. Write a program to find out the opening mode of a file. Use fcntl*/

#include <stdio.h>//for printf
#include <fcntl.h>//for O_RDONLY, fcntl
#include <unistd.h>// for open,close
#include <stdlib.h>//for exit

void check_file_mode(const char *filename) {
    // Open the file
    int fd = open(filename, O_RDONLY);  
    // this opens the file in read-only mode
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Get the file status flags
    int flags = fcntl(fd, F_GETFL);
    /*fcntl: This is a system call used to perform various operations on file descriptors.*/
    //int fcntl(int fd, int cmd, ... /* arg */);
    /*cmd:The command specifying the operation to perform. The value of cmd determines what operation fcntl will perform. */
    //here we are getting file status flags
    //on success fcntl return the current flags
    //for F_GETFl arg is not used
    if (flags == -1) {
        perror("fcntl");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Extract the access mode
    int access_mode = flags & O_ACCMODE;
    /*This line extracts the access mode of the file by applying a bitwise AND operation between the flags and O_ACCMODE. 
    O_ACCMODE is a mask used to isolate the access mode bits from the file status flags.*/

    // Determine the mode and print it
    if (access_mode == O_RDONLY) {
        printf("File opened in read-only mode\n");
    } else if (access_mode == O_WRONLY) {
        printf("File opened in write-only mode\n");
    } else if (access_mode == O_RDWR) {
        printf("File opened in read-write mode\n");
    } else {
        printf("Unknown mode\n");
    }

    // Close the file descriptor
    close(fd);
}

int main() {
    const char *filename = "f2.txt";  // Replace with your file name
    check_file_mode(filename);
    return 0;
}

/*output:
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 12.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
File opened in read-only mode*/
