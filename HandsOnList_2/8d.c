// sigalrm_alarm.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigalrm_handler(int signum) {
    printf("Caught SIGALRM (Alarm Clock)\n");
    exit(0);
}

int main() {
    // Set up signal handler for SIGALRM
    if (signal(SIGALRM, sigalrm_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    // Set an alarm for 5 seconds
    alarm(5);

    printf("Waiting for SIGALRM signal (will occur after 5 seconds)...\n");
    pause();

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 8d.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Waiting for SIGALRM signal (will occur after 5 seconds)...
Caught SIGALRM (Alarm Clock)*/