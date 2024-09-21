//Kunal Agarwal MT2024083
/*8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)*/

// sigsegv_signal.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV (Segmentation Fault)\n");
    exit(1);
}

int main() {
    // Set up signal handler for SIGSEGV
    if (signal(SIGSEGV, sigsegv_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    // Cause a segmentation fault
    int *p = NULL;
    *p = 42;

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 8a.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Caught SIGSEGV (Segmentation Fault)*/