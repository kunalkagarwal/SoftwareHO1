//Kunal agarwal MT2024083
//4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // File name to open.
    //This creates a pointer reference to the string;
    char *filename = "existingfile.txt";

    //the open function call is used to open the file specified by the filename.
    //Syntax:int open(const char *pathname, int flags, mode_t mode);
    //flag is an integer that specifies how a file should be opened .
    //mode specifies the  file permissions.It is required only if you use O_CREAT

    // Open the file with read and write permissions
    int fd = open(filename, O_RDWR|O_CREAT,0777);

    // Check if the file was opened successfully
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Print the file descriptor
    printf("File descriptor for '%s': %d\n", filename, fd);

    // Attempt to open the file with O_EXCL flag (usually used with O_CREAT)
    int fd_excl = open(filename, O_RDWR | O_CREAT | O_EXCL, 0777);

    // Check if the file was opened successfully with O_EXCL flag
    //The O-EXCL flag fails fails if the file already exists.This flag is usually used in combination with O_CREAT to create a new file exclusively.
    //It is useful for the scenarios where we want to prevent overwritiing an existing file.
    if (fd_excl == -1) {
        perror("open with O_EXCL");
        printf("O_EXCL flag caused the open call to fail as expected.\n");
    } else {
        printf("File descriptor with O_EXCL: %d\n", fd_excl);
        close(fd_excl);
    }

    // Close the original file descriptor
    close(fd);

    return 0;
}


/*output:
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 4.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
File descriptor for 'existingfile.txt': 3
open with O_EXCL: File exists
O_EXCL flag caused the open call to fail as expected.*/