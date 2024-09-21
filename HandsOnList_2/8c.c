#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler for SIGFPE
void handler(int signum) {
    printf("Caught SIGFPE: Division by zero!\n");
    exit(0);
}

int main() {
    // Register the signal handler for SIGFPE
    signal(SIGFPE, handler);

    int i, j;

    // Loop to demonstrate division by zero
    for (i = 0; i < 10; i++) {
        if (i - 5 == 0) {
            printf("Skipping division by zero for i = %d\n", i);
            continue; // Skip the iteration to avoid division by zero
        }
        j = i / (i - 5); // Safe division now
        printf("Result of %d / (%d - 5) = %d\n", i, i, j);
    }

    printf("After for loop\n");
    return 0;
}
