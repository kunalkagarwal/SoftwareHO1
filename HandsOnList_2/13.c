//Kunal Agarwal MT2024083
/*13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigstop_handler(int signum) {
    printf("Caught SIGSTOP signal (but this won't be printed).\n");
}

int main() {
    // Set up the signal handler
    signal(SIGSTOP, sigstop_handler);
    
    printf("Process ID: %d\n", getpid());
    printf("Waiting for SIGSTOP...\n");
    
    // Infinite loop to keep the process running
    while (1) {
        pause(); // Wait for signals
    }
    
    return 0;
}
