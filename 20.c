//Kunal Agarwal MT2024083
/*20. Find out the priority of your running program. Modify the priority with nice command.*/
#include <stdio.h>
#include <stdlib.h>// for exit
#include <sys/time.h>//This includes the definitions for data types used in setpriority and getpriority functions
#include <sys/resource.h>//This includes the definitions for resource operations, specifically for setting and getting the process priority.
#include <unistd.h>//This includes standard symbolic constants and types, such as pid_t (for process IDs) and function prototypes like getpid()

int main() {
    // Get the current process ID
    pid_t pid = getpid();
    //The getpid() function retrieves the process ID of the currently running process and stores it in the variable pid
    //type pid_t is used to represent process IDs.
    // Get the current priority of the process
    int current_priority = getpriority(PRIO_PROCESS, pid);
    //The getpriority function in C is used to retrieve the scheduling priority
    //int getpriority(int which, id_t who);
    /*which: This specifies the type of target you are querying. It can be one of the following:

   PRIO_PROCESS: Get the priority of a specific process.
   PRIO_PGRP: Get the priority of a process group.
   PRIO_USER: Get the priority of a user.*/
//In this case we are getting the priority of the process


/*who: This is the ID of the target you are querying.
If which is PRIO_PROCESS, then who is the process ID (pid_t).
If which is PRIO_PGRP, then who is the process group ID.
If which is PRIO_USER, then who is the user ID (uid_t).
If who is 0, the call applies to the calling process, process group, or user, depending on the value of which.*/

//On success, getpriority returns the nice value (priority) of the specified target.

    if (current_priority == -1) {
        perror("getpriority");
        exit(EXIT_FAILURE);
    }
    printf("Current priority: %d\n", current_priority);

    // Set a new priority for the process (nice value between -20 and 19)
    int new_priority = current_priority + 10; 
    /*This sets a new priority for the process by increasing the nice value by 10. A higher nice value means lower priority. */
    if (new_priority > 19) {
        new_priority = 19; // Limit nice value to 19 (lowest priority) done to ensure it stays within valid limits
    }
    
    if (setpriority(PRIO_PROCESS, pid, new_priority) == -1) {
        /*The setpriority function in C is used to set the scheduling priority (or "nice value") of a process, process group, or user.*/
        //int setpriority(int which, id_t who, int prio);
        // the which and who are the same as getpriority .
        /*prio: The new priority (nice value) to set. The nice value ranges from -20 (highest priority) to 19 (lowest priority).*/
        perror("setpriority");
        exit(EXIT_FAILURE);
    }
    
    printf("Priority set to: %d\n", new_priority);

    
    return 0;
}


/*Output:
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 20.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
Current priority: 0
Priority set to: 10*/