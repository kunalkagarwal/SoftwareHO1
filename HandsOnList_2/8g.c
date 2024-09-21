#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigprof_handler(int signum) {
    printf("Caught SIGPROF (Profiling Timer)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    struct itimerval timer;

    signal(SIGPROF, sigprof_handler);

    // Configure the timer to trigger SIGPROF in 5 seconds
    timer.it_value.tv_sec = 5; // Initial delay
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; // No periodic interval
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    printf("Waiting for SIGPROF (Setitimer). It will trigger in 5 seconds...\n");
    while(1); // Wait for signals

    return 0;
}