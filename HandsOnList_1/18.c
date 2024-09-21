//  Rollno: MT2024083
//  Name : Kunal Agarwal

/*
18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
*/



#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define RECORD_SIZE 20  // Size of each record including newline

// Locking function
void apply_lock(int fd, off_t offset, int length, int lock_type) {
    struct flock lock_config = {
        .l_type = lock_type,
        .l_whence = SEEK_SET,
        .l_start = offset,
        .l_len = length
    };
    if (fcntl(fd, F_SETLKW, &lock_config) == -1) {
        perror("Error applying lock");
        exit(EXIT_FAILURE);
    }
    printf("Lock %s\n", lock_type == F_RDLCK ? "acquired" : "released");
}

// Process record based on mode
void process_record(int fd, int index, const char *record_data, int write_mode) {
    off_t file_offset = index * RECORD_SIZE;
    apply_lock(fd, file_offset, RECORD_SIZE, write_mode ? F_WRLCK : F_RDLCK);

    lseek(fd, file_offset, SEEK_SET);
    if (write_mode) {
        write(fd, record_data, RECORD_SIZE);
        printf("Record %d updated: %s\n", index + 1, record_data);
    } else {
        char read_buffer[RECORD_SIZE];
        read(fd, read_buffer, RECORD_SIZE);
        printf("Record %d read: %s\n", index + 1, read_buffer);
    }

    printf("Press Enter to unlock...\n");
    getchar();  // To consume the leftover newline from scanf
    getchar();  // To wait for user input

    apply_lock(fd, file_offset, RECORD_SIZE, F_UNLCK);
}

int main() {
    int file_desc = open("18.txt", O_RDWR | O_CREAT, 0666);
    if (file_desc == -1) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    int block_number, operation_mode;
    printf("Enter block number (1, 2, 3): ");
    scanf("%d", &block_number);

    if (block_number < 1 || block_number > 3) {
        printf("Invalid block number. Exiting...\n");
        close(file_desc);
        return EXIT_FAILURE;
    }

    printf("Select operation mode (1 for read, 2 for write): ");
    scanf("%d", &operation_mode);

    if (operation_mode == 1) {
        process_record(file_desc, block_number - 1, NULL, 0);
    } else if (operation_mode == 2) {
        char new_record[RECORD_SIZE];
        snprintf(new_record, RECORD_SIZE, "New Record %d        \n", block_number);
        process_record(file_desc, block_number - 1, new_record, 1);
    } else {
        printf("Invalid operation mode. Exiting...\n");
    }

    close(file_desc);
    return EXIT_SUCCESS;
}
/*Output
Kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 18.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
Enter block number (1, 2, 3): 2
Select operation mode (1 for read, 2 for write): 2
Lock released
Record 2 updated: New Record 2       
Press Enter to unlock...


*/