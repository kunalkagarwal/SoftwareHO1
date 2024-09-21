//Kunal Agarwal MT2024083
/*10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE*/
// sigsegv_handler.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV (Segmentation Fault)\n");
    exit(1);
}

int main() {
    struct sigaction sa;

    sa.sa_handler = sigsegv_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    // Set up signal handler for SIGSEGV
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Cause a segmentation fault
    int *p = NULL;
    *p = 42;

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 10a.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Caught SIGSEGV (Segmentation Fault)*/