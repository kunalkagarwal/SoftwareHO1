//Kunal Agarwal MT2024083
/*30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    // Step 1: Create shared memory
    key_t key = ftok("shmfile", 65); // Unique key
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Step 2: Attach to shared memory and write data
    char *str = (char *)shmat(shmid, NULL, 0);
    strcpy(str, "Hello, Shared Memory!");
    printf("Data written to shared memory: %s\n", str);

    // Step 3: Detach and reattach with O_RDONLY
    shmdt(str);
    str = (char *)shmat(shmid, NULL, SHM_RDONLY);
    
    // Read data (no attempt to overwrite)
    printf("Data read from shared memory: %s\n", str);

    // Step 4: Detach and remove shared memory
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

/*kunalagarwal@Kunals-MacBook-Air software handson2 % cc 30.c
kunalagarwal@Kunals-MacBook-Air software handson2 % ./a.out
Data written to shared memory: Hello, Shared Memory!
Data read from shared memory: Hello, Shared Memory!*/