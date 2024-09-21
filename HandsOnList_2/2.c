//Kunal Agarwal MT2024083
// 2.Write a program to print the system resource limits. Use getrlimit system call.
#include <stdio.h>//for printf()
#include <sys/resource.h>//getrlimit()
#include <unistd.h>

void print_limit(int resource, const char *name) {
    struct rlimit limit;
    /*This declares a variable limit of type struct rlimit, which will hold the soft and hard limits for the resource*/
    /*The struct rlimit contains two fields:
    rlim_cur: the current (soft) limit.
    rlim_max: the maximum (hard) limit.*/
    if (getrlimit(resource, &limit) == 0) {
        /*getrlimit(resource, &limit): This system call retrieves the resource limits for the specified resource and stores them in the limit struct. It returns 0 on success.*/
        printf("%s: soft limit = %llu, hard limit = %llu\n", name, (unsigned long long)limit.rlim_cur, (unsigned long long)limit.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {
    print_limit(RLIMIT_CPU, "CPU time");
    print_limit(RLIMIT_FSIZE, "File size");
    print_limit(RLIMIT_DATA, "Data segment size");
    print_limit(RLIMIT_STACK, "Stack size");
    print_limit(RLIMIT_CORE, "Core file size");
    print_limit(RLIMIT_RSS, "Resident set size");
    print_limit(RLIMIT_NOFILE, "Open files");
    print_limit(RLIMIT_AS, "Address space");

    return 0;
}

