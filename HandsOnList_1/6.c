//Kunal Agarwal MT2024083
//6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls


//STDIN: Refers to standard input, which is the default source of input data for a program. 
//By default, it is associated with the keyboard input (file descriptor 0).
//STDOUT: Refers to standard output, which is the default destination for output data from a program. 
//By default, it is associated with the terminal or console output (file descriptor 1).

//read System Call:
//Used to read data from a file descriptor.
//Syntax: ssize_t read(int fd, void *buf, size_t count);
//Parameters:
//fd: File descriptor from which to read (e.g., STDIN_FILENO).
//buf: Buffer where the read data is stored.
//count: Number of bytes to read.
//Returns: The number of bytes read, or -1 on error.

//write System Call:
// Used to write data to a file descriptor.
// Syntax: ssize_t write(int fd, const void *buf, size_t count);
// Parameters:
// fd: File descriptor where to write the data (e.g., STDOUT_FILENO).
// buf: Buffer containing the data to be written.
// count: Number of bytes to write.
// Returns: The number of bytes written, or -1 on error.


#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    ssize_t bytesdata;
    //ssize_t is a data type used to represent the size of a block of data that has been read or written, or a count of bytes. I
    //If read() returns a positive value, it means that many bytes were read from the file descriptor. 
    //If it returns 0, it means the end of the file (EOF) has been reached. If it returns -1, it indicates an error occurred during the read operation.
    // Loop to continuously read from STDIN and write to STDOUT
    while ((bytesdata = read(0, buffer, BUFFER_SIZE)) > 0) {
           //0 is the file decsriptor for STDIN
           //The while loop runs until there is EOF
        if (write(1, buffer, bytesdata) == -1) {
            //1 is the file descriptor for STDOUT
            // Write error to STDERR
            write(2, "Error writing to STDOUT\n", 24);
            //2 is the file descriptor for STDERR
            //24 is written because the write system call requires you to specify the exact number of bytes you want to write
            exit(EXIT_FAILURE);
        }
    }

    if (bytesdata == -1) {
        // Read error
        write(2, "Error reading from STDIN\n", 25);
        exit(EXIT_FAILURE);
    }

    return 0;
}

/*output
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 6.c       
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
hello
hello*/