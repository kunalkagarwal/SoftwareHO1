//Kunal Agarwal MT2024083
//29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
//SCHED_RR)
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    int current_policy = sched_getscheduler(pid);

    if (current_policy == -1) {
        perror("sched_getscheduler");
        return EXIT_FAILURE;
    }

    printf("Current policy: %s\n", 
           (current_policy == SCHED_FIFO) ? "SCHED_FIFO" :
           (current_policy == SCHED_RR) ? "SCHED_RR" : "SCHED_OTHER");

    struct sched_param param;
    param.sched_priority = 1;

    if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler");
        return EXIT_FAILURE;
    }

    printf("Scheduler policy changed to: SCHED_RR\n");
    return EXIT_SUCCESS;
}

/*Output:

// satyam@satyam-X542UQ:~/Desktop/Software_system-File$ gcc 29.c -o 29
// satyam@satyam-X542UQ:~/Desktop/Software_system-File$ sudo ./29
// Current policy: SCHED_OTHER
// New policy: SCHED_RR*/