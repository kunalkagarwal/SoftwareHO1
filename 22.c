//Kunal Agarwal MT2024083
/*22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
int main() {
    int fd;
    pid_t pid;
    const char *filename = "example.txt";

    // Open the file for writing
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Fork the process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        const char *child_message = "Hello ,Iam  the child process!\n";
        if (write(fd, child_message, strlen(child_message)) < 0) {
              // writes the message to the file.
             // ssize_t write(int fd, const void *buf, size_t count);
            // int fd: The file descriptor where the data will be written. This descriptor is obtained from functions like open(), socket(), or pipe().
           // const void *buf: A pointer to the buffer containing the data to be written. The data is pointed to by this pointer.
          // size_t count: The number of bytes to write from the buffer.

            perror("write (child)");
            close(fd);
            exit(EXIT_FAILURE);
        }
        close(fd);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process

         if (wait(NULL) < 0) {
            perror("wait");
            exit(EXIT_FAILURE);
        }
        //By calling wait(), the parent process pauses execution until the child process exits, ensuring that the child process has completed its task before the parent proceeds.
        //If successful, wait() returns the process ID of the terminated child. 
        //If there are no child processes or if an error occurs, it returns -1.

        const char *parent_msg = "Hello ,Iam the parent process!\n";
        if (write(fd, parent_msg, strlen(parent_msg)) < 0) {
            perror("write (parent)");
            close(fd);
            exit(EXIT_FAILURE);
        }
        close(fd);

       
       
    }

    return 0;
}

/*Output:
Hello ,Iam  the child process!
Hello ,Iam the parent process!*/