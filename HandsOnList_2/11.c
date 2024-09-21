// Kunal Agarwal MT2024083
/*11.Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.*/


#include <stdio.h>
#include <signal.h>//For signal handling functions like sigaction
#include <unistd.h>

void ignore_sigint(int signum) {
    /*This function is called when the SIGINT signal (triggered by pressing Ctrl+C) is caught.
It simply prints "SIGINT ignored" and does nothing else, effectively ignoring the signal.*/
    printf("SIGINT ignored\n");
}

int main() {
    struct sigaction sa;
   sa.sa_handler = ignore_sigint;
   /*We create a sigaction structure sa and set its sa_handler to the ignore_sigint function.
   The sigaction(SIGINT, &sa, NULL) system call applies the new action to the SIGINT signal.*/
    sigaction(SIGINT, &sa, NULL);
    printf("SIGINT is now ignored. Press Ctrl+C...\n");

    sleep(5);  // Ignore SIGINT for 5 seconds

    // Reset SIGINT to default
    sa.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sa, NULL);
    printf("SIGINT restored. Press Ctrl+C to terminate.\n");

    while (1) {
        pause();  /*The program enters an infinite loop, using the pause() function to wait for signals.*/
    }

    return 0;
}

/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 11.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
SIGINT is now ignored. Press Ctrl+C...
^CSIGINT ignored
SIGINT restored. Press Ctrl+C to terminate.
^C*/