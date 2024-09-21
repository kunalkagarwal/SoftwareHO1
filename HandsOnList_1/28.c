//Kunal Agarwal MT2024083
/*28. Write a program to get maximum and minimum real time priority.*/
#include <stdio.h>
#include <sched.h>//This header file includes definitions for the POSIX scheduling functions, such as sched_get_priority_max() and sched_get_priority_min().
#include <errno.h>

int main() {
    int max_priority, min_priority;

    max_priority = sched_get_priority_max(SCHED_RR); // SCHED_RR for real-time round-robin scheduling
    //sched_get_priority_max(int policy): This function returns the maximum priority value for a given scheduling policy. 
    //policy:  It takes one parameter.The scheduling policy for which you want to retrieve the maximum priority. 
    if (max_priority == -1) {
        perror("Error getting maximum real-time priority");
        return 1;
    }

    min_priority = sched_get_priority_min(SCHED_RR); // SCHED_RR for real-time round-robin scheduling
    //sched_get_priority_min(int policy): This function returns the minimum priority value for a given scheduling policy. Like sched_get_priority_max(), it also takes one parameter:policy
    if (min_priority == -1) {
        perror("Error getting minimum real-time priority");
        return 1;
    }

    printf("Maximum real-time priority: %d\n", max_priority);
    printf("Minimum real-time priority: %d\n", min_priority);

    return 0;
}
/*
Kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 28.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
Maximum real-time priority: 47
Minimum real-time priority: 15*/