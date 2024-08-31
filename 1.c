// Kunal Agarwal MT2024083
/* 1. Create the following types of a files using system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    const char *target_file = "hi.txt";
    const char *soft_link_name = "kunal_soft_link";
    const char *hard_link_name = "kunal_hard_link";
    const char *fifo_name = "kunal_fifo";

    // Creating a symbolic link (soft link)
    if (symlink(target_file, soft_link_name) == -1) {
        perror("symlink");
        return 1;
    }
    printf("Symbolic link '%s' created.\n", soft_link_name);

    // Creating a hard link
    if (link(target_file, hard_link_name) == -1) {
        perror("link");
        return 1;
    }
    printf("Hard link '%s' created.\n", hard_link_name);

    // Creating a FIFO (named pipe)
    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo");
        return 1;
    }
    printf("FIFO '%s' created.\n", fifo_name);

    return 0;
}
