//Kunal Agarwal MT2024083
/*5. Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.*/
#include <stdio.h>//for snprintf()
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int i;
    char filename[20];
    for (i = 0; i < 5; i++) {
        snprintf(filename, sizeof(filename), "file_%d.txt", i + 1);
        //The snprintf function in C is used to format a string and write it to a character array, ensuring that the output does not exceed a specified size
        //int snprintf(char *str, size_t size, const char *format, ...);
        //char *str: A pointer to the character array where the formatted string will be written.
        //size_t size: The maximum number of characters to write to str, including the null terminator.
        //A format string that specifies how subsequent arguments (provided after format) are to be formatted.
       //...: A variable number of additional arguments that will be formatted according to the format string.
        int fd = open(filename, O_CREAT | O_WRONLY, 0644);
        if (fd == -1) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
    }

    while (1) {
        sleep(3);
    }

    return 0;
}


/*output
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out &            
[1] 72407
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % lsof -p 72407
COMMAND   PID         USER   FD   TYPE DEVICE SIZE/OFF    NODE NAME
a.out   72407 kunalagarwal  cwd    DIR   1,17     2368 1299212 /Users/kunalagarwal/software systems handson 1
a.out   72407 kunalagarwal  txt    REG   1,17    33608 1640828 /Users/kunalagarwal/software systems handson 1/a.out
a.out   72407 kunalagarwal    0u   CHR  16,42   0t4567     861 /dev/ttys042
a.out   72407 kunalagarwal    1u   CHR  16,42   0t4567     861 /dev/ttys042
a.out   72407 kunalagarwal    2u   CHR  16,42   0t4567     861 /dev/ttys042
a.out   72407 kunalagarwal    3w   REG   1,17        0 1336750 /Users/kunalagarwal/software systems handson 1/file_1.txt
a.out   72407 kunalagarwal    4w   REG   1,17        0 1336751 /Users/kunalagarwal/software systems handson 1/file_2.txt
a.out   72407 kunalagarwal    5w   REG   1,17        0 1336752 /Users/kunalagarwal/software systems handson 1/file_3.txt
a.out   72407 kunalagarwal    6w   REG   1,17        0 1336753 /Users/kunalagarwal/software systems handson 1/file_4.txt
a.out   72407 kunalagarwal    7w   REG   1,17        0 1336754 /Users/kunalagarwal/software systems handson 1/file_5.txt
kunalagarwal@Kunals-MacBook-Air software systems handson 1 %      */