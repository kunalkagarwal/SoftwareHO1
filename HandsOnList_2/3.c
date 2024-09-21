//Kunal Agarwal MT2024083
/*3.Write a program to set (any one) system resource limit. Use setrlimit system call.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main() {
    struct rlimit limit;

    // Get the current file descriptor limit
    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
     /*getrlimit(RLIMIT_NOFILE, &limit): Retrieves the current resource limits for file descriptors (RLIMIT_NOFILE).*/
        printf("Current file descriptor limit: soft = %llu, hard = %llu\n", 
               (unsigned long long)limit.rlim_cur, 
               (unsigned long long)limit.rlim_max);
    } else {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    // Set the new limit for file descriptors
    limit.rlim_cur = 512; // Setting soft limit to 512
    limit.rlim_max = 1024; // Setting hard limit to 1024 

    if (setrlimit(RLIMIT_NOFILE, &limit) == 0) {
        /*setrlimit(RLIMIT_NOFILE, &limit): Sets new resource limits for the number of file descriptors.*/
        printf("New file descriptor limit set: soft = %llu, hard = %llu\n", 
               (unsigned long long)limit.rlim_cur, 
               (unsigned long long)limit.rlim_max);
    } else {
        perror("setrlimit");
        exit(EXIT_FAILURE);
    }

    return 0;
}
