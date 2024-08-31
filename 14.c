//Kunal Agarwal MT2024083
/*14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
//The stat function is used to get the file status, which includes the mode (type and permissions) of the file.


int main(int argc, char *argv[]) {
    if (argc != 2) {
        //Checks if the number of command-line arguments is not equal to 2. 
        //The program expects exactly one argument (the file path).

        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct stat fileStat;
    //his structure will hold the information about the file retrieved by the stat function.

    // Get file status
    if (stat(argv[1], &fileStat) < 0) {
        //The stat() function in C is used to retrieve information about a file specified by a file path.
        //int stat(const char *path, struct stat *buf);
       // const char *path: A string that specifies the path to the file whose information is being requested. This can be an absolute or relative path.
      // struct stat *buf: A pointer to a struct stat where the file information will be stored.
        perror("stat");
        return EXIT_FAILURE;
    }

    // Check the type of file
    if (S_ISREG(fileStat.st_mode)) {
        printf("%s is a regular file.\n", argv[1]);
    } else if (S_ISDIR(fileStat.st_mode)) {
        printf("%s is a directory.\n", argv[1]);
    } else if (S_ISLNK(fileStat.st_mode)) {
        printf("%s is a symbolic link.\n", argv[1]);
    } else if (S_ISCHR(fileStat.st_mode)) {
        printf("%s is a character device.\n", argv[1]);
    } else if (S_ISBLK(fileStat.st_mode)) {
        printf("%s is a block device.\n", argv[1]);
    } else if (S_ISFIFO(fileStat.st_mode)) {
        printf("%s is a FIFO (named pipe).\n", argv[1]);
    } else if (S_ISSOCK(fileStat.st_mode)) {
        printf("%s is a socket.\n", argv[1]);
    } else {
        printf("Unknown file type.\n");
    }
    //If a file type is identified, this prints the type of the file along with the file name

    return EXIT_SUCCESS;
}

/*Output:
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 14.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out 14.c
14.c is a regular file.*/