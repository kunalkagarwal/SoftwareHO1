//Kunal Agarwal MT2024083
//3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
#include <stdio.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // File name to create.
    //This declares pointer to a string that stores the name of the file to be created
   // int creat(const char *pathname, mode_t mode);
 
    char *filename = "myfile.txt";

    // Create a file with read and write permissions for the owner
    //The creat() system call in C is used to create a new file or to open and truncate an existing file. 
    //If there is no such file it creates a new file if there already exists the file it opens it and truncates it to a length 0.

    int fd = creat(filename, 0777);

    // // Check if the file was created successfully.If error then file descriptor returns -1;
    // The file descriptor is a unique identifier for the opened file and is used in subsequent system calls to refer to that file.
    if (fd == -1) {
        perror("creat failed");
        exit(EXIT_FAILURE);
    }

    // // Print the file descriptor
    printf("File descriptor for '%s': %d\n", filename, fd);

    // // Close the file
    close(fd);

    return 0;
}


/*Output
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 3.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
File descriptor for 'myfile.txt': 3*/