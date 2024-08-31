//Kunal agarwal MT2024083
/*16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// Function to acquire a write lock
void write_lock(int fd) {
    struct flock lock;

    lock.l_type = F_WRLCK;  // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // Lock the whole file

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - write lock");
        exit(1);
    }
    printf("Write lock acquired.\n");
}

// Function to acquire a read lock
void read_lock(int fd) {
    struct flock lock;

    lock.l_type = F_RDLCK;  // Read lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // Lock the whole file

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - read lock");
        exit(1);
    }
    printf("Read lock acquired.\n");
}

// Function to release a lock
void unlock(int fd) {
    struct flock lock;

    lock.l_type = F_UNLCK;  // Unlock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // Unlock the whole file

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl - unlock");
        exit(1);
    }
    printf("Lock released.\n");
}

int main() {
    int fd = open("hi.txt", O_RDWR | O_CREAT, 0644);  // Open file for read and write
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Acquire a write lock
    write_lock(fd);

    // Perform writing
    if (write(fd, "This is a test.", 15) == -1) {
        perror("write");
        unlock(fd);  // Ensure to unlock before exiting
        close(fd);
        exit(1);
    }
    getchar();

    // Release the write lock
    unlock(fd);

    // Re-open file to demonstrate read lock
    close(fd);  // Close and reopen to ensure locks are released
    fd = open("hi.txt", O_RDWR);  // Open file for read and write
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Acquire a read lock
    read_lock(fd);

    // Perform reading
    char buffer[20];
    if (read(fd, buffer, sizeof(buffer) - 1) == -1) {
        perror("read");
        unlock(fd);  // Ensure to unlock before exiting
        close(fd);
        exit(1);
    }
    buffer[15] = '\0';  // Null-terminate the buffer
    printf("Read data: %s\n", buffer);

    // Release the read lock
    unlock(fd);

    close(fd);
    return 0;
}

/*kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 16.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
Write lock acquired.

Lock released.
Read lock acquired.
Read data: This is a test.
Lock released.*/