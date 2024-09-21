//Kunal Agarwal MT2024083
/*1.Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
c. ITIMER_PROF*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signum) {
    printf("ITIMER_PROF timer expired\n");
}

int main() {
    struct itimerval timer;
    struct sigaction sa;

    // Set up signal handler
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGPROF, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Set timer for 1 second and 0 microseconds
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }

    // Busy-wait to use CPU time
    while (1) {
        // You can add some CPU workload here
    }

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 1c.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
ITIMER_PROF timer expired*/