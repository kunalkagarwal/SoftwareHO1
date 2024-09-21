// sigint_signal.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("Caught SIGINT (Interrupt from keyboard)\n");
    exit(0);
}

int main() {
    // Set up signal handler for SIGINT
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for SIGINT signal (press Ctrl+C to send it)...\n");
    while (1) {
        pause();
    }

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 8b.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Waiting for SIGINT signal (press Ctrl+C to send it)...
^CCaught SIGINT (Interrupt from keyboard)*/