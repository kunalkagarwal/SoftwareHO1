
//Kunal Agarwal MT2024083

/*9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

void print_file_info(const char *filepath) {
    struct stat fileStat;

    // Get file status
    if (stat("f2.txt", &fileStat) < 0) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    // Print inode
    printf("Inode: %llu\n", (unsigned long long)fileStat.st_ino);

    // Print number of hard links
    printf("Number of hard links: %u\n", (unsigned int)fileStat.st_nlink);

    // Print UID
    printf("UID: %u\n", fileStat.st_uid);

    // Print GID
    printf("GID: %u\n", fileStat.st_gid);

    // Print file size
    printf("Size: %lld bytes\n", (long long)fileStat.st_size);

    // Print block size
    printf("Block size: %u bytes\n", (unsigned int)fileStat.st_blksize);

    // Print number of blocks
    printf("Number of blocks: %lld\n", (long long)fileStat.st_blocks);

    // Print time of last access
    printf("Last access time: %s", ctime(&fileStat.st_atime));

    // Print time of last modification
    printf("Last modification time: %s", ctime(&fileStat.st_mtime));

    // Print time of last change
    printf("Last change time: %s", ctime(&fileStat.st_ctime));
}

int main() {
    const char *filepath="f2.txt";
    print_file_info(filepath);

    return 0;
}
 

 /*Output:
 kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 9.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
Inode: 1336410
Number of hard links: 1
UID: 501
GID: 20
Size: 1654 bytes
Block size: 4096 bytes
Number of blocks: 8
Last access time: Sat Aug 24 15:30:38 2024
Last modification time: Mon Aug 19 21:31:53 2024
Last change time: Sat Aug 24 15:30:38 2024*/