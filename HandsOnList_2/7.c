//Kunal Agarwal MT2024083
//7.Write a simple program to print the created thread ids.
#include <stdio.h>
#include <pthread.h>// for thread handling
#include <unistd.h>

// Function executed by each thread
void* printThreadID(void* arg) {
    printf("Thread ID: %llu\n", (unsigned long long)pthread_self());
    //pthread_self(): Returns the unique ID of the thread that calls this function
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
     //declares 2 variables of type pthread_t
    // Create two threads
    pthread_create(&thread1, NULL, printThreadID, NULL);
    pthread_create(&thread2, NULL, printThreadID, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread completed.\n");
   //pthread_join() ensures that the main thread will wait for both thread1 and thread2 to complete before proceeding further. Without pthread_join(), the main thread could finish before the created threads complete.
    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 7.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Thread ID: 6166474752
Thread ID: 6167048192*/