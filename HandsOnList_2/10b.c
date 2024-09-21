// sigint_handler.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("Caught SIGINT (Interrupt from keyboard)\n");
    exit(0);
}

int main() {
    struct sigaction sa;

    sa.sa_handler = sigint_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    // Set up signal handler for SIGINT
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Wait indefinitely
    printf("Waiting for SIGINT signal (press Ctrl+C to send it)...\n");
    while (1) {
        pause();
    }

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 10b.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Waiting for SIGINT signal (press Ctrl+C to send it)...
^CCaught SIGINT (Interrupt from keyboard)*/