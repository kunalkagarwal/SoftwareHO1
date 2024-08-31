//Kunal Agarwal MT2024083
/* Q17b.Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>// allows the use of open
#include <unistd.h>// allows the use of close,read,write

int main() {
    int fd = open("ticket.txt", O_RDWR);//opens the file in the read-write mode
    if (fd == -1) {
        perror("Error opening file");//this is executed in case file is not opened
        return 1;
    }

    // Applying a write lock
    struct flock lock;//declares a flock structure that is used to specify a file lock
    lock.l_type = F_WRLCK;  // Write lock(l_type sets the type of the lock)
    lock.l_whence = SEEK_SET;//sets the starting point of the lock to the beginning of the file.l_whence indicates the reference point for l_start.
    lock.l_start = 0;//specifies the starting offset of the lock.0 means the lock starts from the beginning of the file
    lock.l_len = 0;  //l_len=0 specifies the lock should cover the entire file.

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        //Applies the lock defined in the lock structure to the file. 
        //F_SETLKW means it will wait if the lock cannot be immediately applied.
       //fcntl is a system call in Unix-like operating systems that performs various operations on file descriptors. 
       //used for different tasks like manipulating file descriptors, setting file locks, and modifying file descriptor flags.
        perror("Error applying lock");
        close(fd);
        return 1;
    }

    // Reading the ticket number
    FILE *file = fdopen(fd, "r+");//converts the fd into a FILE stream for reading and writing
    //fdopen converts an existing file descriptor into a FILE * stream.
    //No New File is created by fdopen; it points to the existing file associated with the given file descriptor.
    if (file == NULL) {
        perror("Error opening file stream");
        close(fd);
        return 1;
    }
    getchar();
    //getchar();: Waits for the user to press Enter before proceeding.
    
    int ticket_number;
    fscanf(file, "%d", &ticket_number);
    //reads an integer from a file and stores it in ticket number

    // Incrementing the ticket number
    ticket_number++;

                
    rewind(file);// Moves the file pointer back to the beginning of the file so that the new ticket number can overwrite the old one.
    fprintf(file, "%d", ticket_number);//writes the incremented ticket number to the file
    fflush(file);//flushes the output buffer to ensure that the data is written to the file immideately

    // Releasing the lock
    lock.l_type = F_UNLCK;//changes the lock type to 'F_UNLCK' which means the lock will be released
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        //releases the lock on the file
        perror("Error releasing lock");
    }

    fclose(file);
    close(fd);

    printf("New ticket number: %d\n", ticket_number);
    return 0;
}

/*output
Kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 17b.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out

New ticket number: 2*/