
//Kunal Agarwal MT2024083

/*10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open the file with read/write mode, create it if it doesn't exist
    int fd = open("testfile.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Write the first 10 bytes to the file
    const char *data1 = "1234567890"; // 10 bytes
    ssize_t bytes_written = write(fd, data1, 10);
    if (bytes_written < 0) {
        perror("Failed to write data");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Move the file pointer by 10 bytes
    off_t offset = lseek(fd, 10, SEEK_CUR);
    if (offset == (off_t) -1) {
        perror("Failed to seek");
        close(fd);
        exit(EXIT_FAILURE);
    } else {
        printf("lseek returned offset: %lld\n", (long long)offset);
    }

    // Write the second 10 bytes to the file
    const char *data2 = "abcdefghij"; // 10 bytes
    bytes_written = write(fd, data2, 10);
    if (bytes_written < 0) {
        perror("Failed to write data");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file
    close(fd);

    return 0;
}
/*Output
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 10.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
lseek returned offset: 20
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % od -c testfile.txt
0000000    1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
0000020   \0  \0  \0  \0   a   b   c   d   e   f   g   h   i   j   O   r
0000040    i   g   i   n   a   D   u   p       d   e   s   D   u   p   2
0000060        d   e   F   c   n   t   l       d   O   r   i   g   i   n
0000100    a   D   u   p       d   e   s   D   u   p   2       d   e   F
0000120    c   n   t   l       d   O   r   i   g   i   n   a   D   u   p
0000140        d   e   s   D   u   p   2       d   e   F   c   n   t   l
0000160        d                                                        
0000162
*/