//Kunal Agarwal MT2024083
/*5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.*/
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/sysctl.h>

int main() {
    // Maximum length of arguments to exec functions
    printf("Max length of arguments: %ld bytes\n", sysconf(_SC_ARG_MAX));

    // Maximum number of simultaneous processes per user ID
    printf("Max simultaneous processes: %ld\n", sysconf(_SC_CHILD_MAX));

    // Number of clock ticks per second
    printf("Clock ticks per second: %ld\n", sysconf(_SC_CLK_TCK));

    // Maximum number of open files
    struct rlimit rl;
    getrlimit(RLIMIT_NOFILE, &rl);
    printf("Max open files: %llu\n", (unsigned long long)rl.rlim_cur);

    // Size of a page
    printf("Page size: %ld bytes\n", sysconf(_SC_PAGESIZE));

    // Total number of pages in physical memory
    int mib[2] = {CTL_HW, HW_PHYSMEM};
    uint64_t total_mem;
    size_t len = sizeof(total_mem);
    sysctl(mib, 2, &total_mem, &len, NULL, 0);
    printf("Total memory: %llu bytes\n", (unsigned long long)total_mem);

    // Free memory is not directly available in macOS via sysctl, so we skip this part

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 5.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Max length of arguments: 1048576 bytes
Max simultaneous processes: 1333
Clock ticks per second: 100
Max open files: 1048575
Page size: 16384 bytes
Total memory: 7968243712 bytes*/