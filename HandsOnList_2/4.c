//Kunal Agarwal MT2024083
/*4.Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.*/
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
    struct timespec start, end;
    pid_t ppid;
    int i;

    // Get the starting time
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Execute getppid() 100 times
    for (i = 0; i < 100; i++) {
        ppid = getppid();
    }

    // Get the ending time
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate the time taken in nanoseconds
    long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    long elapsed_ns = seconds * 1000000000 + nanoseconds;

    printf("Time taken for 100 getppid() calls: %ld nanoseconds\n", elapsed_ns);

    return 0;
}

