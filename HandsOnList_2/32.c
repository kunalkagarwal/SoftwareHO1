#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

// Define union semun only if it's not already defined (on non-Apple systems)
#ifndef __APPLE__
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
#endif

// Function to initialize semaphore value
void initialize_semaphore(int semid, int semnum, int init_val) {
    union semun sem_union;
    sem_union.val = init_val;
    semctl(semid, semnum, SETVAL, sem_union);
}

// Function to perform semaphore operation (lock or unlock)
void semaphore_operation(int semid, int semnum, int op) {
    struct sembuf sb;
    sb.sem_num = semnum;
    sb.sem_op = op;  // Positive for unlock, negative for lock
    sb.sem_flg = 0;
    semop(semid, &sb, 1);
}

int main() {
    key_t key = ftok("semfile", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);  // Create binary semaphore
    initialize_semaphore(semid, 0, 1);  // Initialize to 1 (unlocked)
    int ticket_number = 0;
    for (int i = 0; i < 5; i++) {
        semaphore_operation(semid, 0, -1);  // Lock semaphore
        // Critical section: Generate ticket number
        printf("Generating ticket number...\n");
        ticket_number++;
        printf("Ticket number: %d\n", ticket_number);
        sleep(1);  // Simulating work
        semaphore_operation(semid, 0, 1);  // Unlock semaphore
    }
    return 0;
}
