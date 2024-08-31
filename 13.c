//Kunal Agarwal MT2024083
/*13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).*/
#include <stdio.h>// for perror,printf()
#include <stdlib.h>//for exit()
#include <unistd.h>// for STDIN_FILENO.
#include <sys/select.h>// for select function and related macros
#include <time.h> 

int main() {
    fd_set read_fds;
    //fd_set is a data type used to represent a set of file descriptors
    //It is a type used to define a set of file descriptors that you want to monitor using the select function.
    struct timeval timeout;
    //The struct timeval type is used to specify time intervals in seconds and microseconds. 
    //It is particularly relevant in the context of functions like select, which allows you to specify a timeout period for waiting on multiple file descriptors.
    //struct timeval is used to specify the amount of time to wait before the select function times out. 
    int retval;
     //defines an integer to store the return value of the select function

    FD_ZERO(&read_fds);
    /*Initializes the read_fds set to be empty. This is necessary before adding file descriptors to it.*/
    FD_SET(STDIN_FILENO, &read_fds);
/*Adds the standard input file descriptor (STDIN_FILENO, typically 0) to the read_fds set.
 This means select will monitor standard input for readability.*/
    // Set up the timeout
    timeout.tv_sec = 10;  // 10 seconds
    timeout.tv_usec = 0;  // 0 microseconds
    //combined this this specifies a total timeout of 10seconds
    // Wait for input or timeout
    retval = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);
    /*The select function is a system call used  to monitor multiple file descriptors to see if they are ready for I/O operations (such as reading or writing).
     It allows a program to efficiently handle multiple input/output operations by waiting until one or more file descriptors become ready.*/
    
    //int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
    
    /*nfds:The highest file descriptor value plus one. 
    This tells select the range of file descriptors to check. 
    If you're only monitoring stdin, for example, this value would be STDIN_FILENO + 1.*/
    
    /*readfds:A pointer to an fd_set structure that specifies the file descriptors to monitor for readability. */
  
    /*writefds:A pointer to an fd_set structure that specifies the file descriptors to monitor for writability. */  
    
    /*exceptfds:A pointer to an fd_set structure that specifies the file descriptors to monitor for exceptional conditions (e.g., out-of-band data).*/


   /*timeout:A pointer to a struct timeval that specifies the maximum amount of time to wait. 
    If timeout is NULL, select will block indefinitely until at least one file descriptor becomes ready.*/
  
  //returns the number of file descriptors that are ready for the requested I/O operation
 
 if (retval == -1) {
        perror("select()");
        exit(EXIT_FAILURE);
    } else if (retval) {
        // Data is available
        printf("Data is available now.\n");
    } else {
        // Timeout occurred
        printf("No data available within 10 seconds.\n");
    }

    return 0;
}
  




/*output
  kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 13.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
l
Data is available now.
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % l
zsh: command not found: l
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
No data available within 10 seconds.*/