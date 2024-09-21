
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigfpe_handler(int signum) {
    printf("Caught SIGFPE (Floating-point Exception)\n");
    exit(1);
}

int main() {
    struct sigaction sa;

    sa.sa_handler = sigfpe_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Explicitly raise SIGFPE to test the handler
    raise(SIGFPE);

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 10c.c -lm
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Caught SIGFPE (Floating-point Exception)*/