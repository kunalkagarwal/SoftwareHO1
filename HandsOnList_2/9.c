//Kunal Agarwal MT2024083
/*9.Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call*/



/*SIGINT stands for "Signal Interrupt." It is a signal sent to a program to interrupt its execution. */
/*A signal handler is a function in a program that is called when a specific signal is received. It allows a program to "handle" or respond to signals in a custom way.*/
#include <stdio.h>
#include <signal.h>/*used for handling signals, such as SIGINT. It provides the signal() function and symbolic constants like SIGINT.*/
#include <unistd.h>// for sleep and pause

// Signal handler function to ignore SIGINT
void ignore_sigint(int sig) {
    /*The sig parameter will hold the signal number that triggered the handler. In this case, it would be SIGINT.*/
    printf("SIGINT received, but ignored.\n");
}

int main() {
    // Set the signal handler for SIGINT to ignore it
    signal(SIGINT, ignore_sigint);
   /*SIGINT: This is the signal number for interrupt signals (triggered by pressing Ctrl + C).*/
   /*This is the name of the custom signal handler function that will handle SIGINT by ignoring it.*/
    printf("Press Ctrl + C (SIGINT will be ignored for 5 seconds).\n");
    sleep(5);

    // Reset the signal handler for SIGINT to its default behavior
    signal(SIGINT, SIG_DFL);
    /*signal(SIGINT, SIG_DFL);: This resets the signal handler for SIGINT back to its default behavior.
SIG_DFL: This constant stands for "default action," meaning the program will now respond to SIGINT in the default way (typically terminating the program when Ctrl + C is pressed).
*/
    printf("SIGINT reset to default behavior. Press Ctrl + C again.\n");
    
    // Pause the program to wait for signals
    pause();

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 9.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Press Ctrl + C (SIGINT will be ignored for 5 seconds).
^CSIGINT received, but ignored.
SIGINT*/