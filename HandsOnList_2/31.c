//Kunal Agarwal MT2024083
/*31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore*/
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Create a binary semaphore (0 or 1)
    sem_t *binary_semaphore = sem_open("/binary_sem", O_CREAT, 0644, 1);
    if (binary_semaphore == SEM_FAILED) {
        perror("sem_open (binary) failed");
        exit(1);
    }

    // Create a counting semaphore (e.g., initial value 3)
    sem_t *counting_semaphore = sem_open("/counting_sem", O_CREAT, 0644, 3);
    if (counting_semaphore == SEM_FAILED) {
        perror("sem_open (counting) failed");
        exit(1);
    }

    // Binary semaphore usage
    sem_wait(binary_semaphore);  // Lock
    printf("Binary semaphore locked.\n");
    sem_post(binary_semaphore);  // Unlock
    printf("Binary semaphore unlocked.\n");

    // Counting semaphore usage
    sem_wait(counting_semaphore);  // Acquire resource
    printf("Counting semaphore decremented.\n");
    sem_post(counting_semaphore);  // Release resource
    printf("Counting semaphore incremented.\n");

    // Clean up
    sem_close(binary_semaphore);
    sem_close(counting_semaphore);
    sem_unlink("/binary_sem");
    sem_unlink("/counting_sem");

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 31.c -lpthread
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Binary semaphore locked.
Binary semaphore unlocked.
Counting semaphore decremented.
Counting semaphore incremented.*/