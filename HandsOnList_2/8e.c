// sigalrm_setitimer.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigalrm_handler(int signum) {
    printf("Caught SIGALRM (Alarm Clock with setitimer)\n");
    exit(0);
}

int main() {
    struct itimerval timer;

    // Set up signal handler for SIGALRM
    if (signal(SIGALRM, sigalrm_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    // Set up timer
    timer.it_value.tv_sec = 5;  // Initial expiration time (5 seconds)
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;  // Interval time (0 seconds, no repeat)
    timer.it_interval.tv_usec = 0;

    // Start timer
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for SIGALRM signal (will occur after 5 seconds)...\n");
    pause();

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 8e.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out 
Waiting for SIGALRM signal (will occur after 5 seconds)...
Caught SIGALRM (Alarm Clock with setitimer)*/