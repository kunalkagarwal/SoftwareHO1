//Kunal Agarwal MT2024083
/*1a.Write a s program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signum) {
    printf("ITIMER_REAL timer expired\n");
}

int main() {
    struct itimerval timer;
    struct sigaction sa;

    // Set up signal handler
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Set timer for 10 seconds and 10 microseconds
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }

    // Wait for timer to expire
    pause();

    return 0;
}
