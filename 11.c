//Kunal Agarwal MT2024083
//Q11. Write a program to open a file, duplicate the file descriptor and append the file with both the
//  descriptors and check whether the file is updated properly or not.
//  a. use dup
//  b. use dup2
//  c. use fcntl 
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

int main() {
    const char *filename = "f1.txt";//defines the file name that the program will open/create
    const char *text1 = "Logging started: Initializing resources...\n";//defines the text that will be written using the original file descriptor
    const char *text2 = "Logging continued: Resources initialized successfully.\n";//defines the text that will be written using the  duplicated file descriptor created by dup
    const char *text3 = "Logging update: Entering main processing loop.\n";//defines the text that will be written using the duplicated file descriptor cretaed by dup2

    // Open the file
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Write using the original descriptor
    write(fd, text1, strlen(text1) );
    //writes the content of the text1 to the file using the original fd.

    // Duplicate the descriptor using dup
    int fd_dup = dup(fd);
    //The dup system call is used to create a copy of a file descriptor.
    //The new file descriptor shares the same underlying file object as the original one, meaning that they both point to the same file 
    //This allows you to write or read from the same file using different file descriptors.
    //dup(fd): This call creates a new file descriptor that points to the same open file as fd.   
    //The new file descriptor is the smallest available file descriptor number greater than or equal to 0.
    write(fd_dup, text2, strlen(text2));
    // writes the  content of the text2 to the file using the duplicated file descriptor fd_dup
    // Duplicate the descriptor using dup2
    
    int fd_dup2 = dup2(fd, fd_dup + 1);
    // The dup2 system call is used to duplicate a file descriptor, just like dup, but with an important difference: it allows you to specify the exact value of the new file descriptor. If the specified new file descriptor is already open, dup2 will close it before duplicating the original file descriptor.
    write(fd_dup2, text3, strlen(text3));

    // Close all descriptors
    close(fd);
    close(fd_dup);
    close(fd_dup2);

    printf("File updated successfully!\n");
    return 0;
}

/*Output:
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 11.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
File updated successfully!*/