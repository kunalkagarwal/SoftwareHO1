//Kunal Agarwal MT2024083
//Q27e Write a program to execute ls -Rl using execvp
#include <unistd.h>
#include <stdio.h>

int main() {
    char *args[] = { "ls", "-Rl", NULL };
    //This array holds the arguments for the ls command like in the execv
    execvp("ls", args);
    //The execvp function is used to execute a file by searching for it in the directories listed in the PATH environment variable.
    //execvp(const char *file, char *const argv[])
    // it is similar to the execv but here absolute path is not necessary
    perror("execvp failed");
    return 1;
}


/*kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 27e.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
total 944
-rw-r--r--@ 1 kunalagarwal  staff   1085 Aug 31 00:18 1.c
-rwxr-xr-x@ 1 kunalagarwal  staff    494 Aug 31 00:18 1.sh
-rw-r--r--@ 1 kunalagarwal  staff   1470 Aug 31 15:07 10.c
-rw-r--r--@ 1 kunalagarwal  staff   2575 Aug 31 15:13 11.c
-rw-r--r--@ 1 kunalagarwal  staff   1869 Aug 31 14:30 12.c
-rw-r--r--@ 1 kunalagarwal  staff   3341 Aug 31 14:08 13.c
-rw-r--r--@ 1 kunalagarwal  staff   2187 Aug 31 15:17 14.c
-rw-r--r--@ 1 kunalagarwal  staff   1619 Aug 31 15:18 15.c
-rw-r--r--@ 1 kunalagarwal  staff   2447 Aug 31 15:19 16.c
-rw-r--r--@ 1 kunalagarwal  staff    871 Aug 31 15:20 17a.c
-rw-r--r--@ 1 kunalagarwal  staff   3043 Aug 31 15:24 17b.c
-rw-r--r--@ 1 kunalagarwal  staff   2732 Aug 31 00:18 18.c
-rw-r--r--@ 1 kunalagarwal  staff     60 Aug 31 15:23 18.txt
-rw-r--r--@ 1 kunalagarwal  staff   2171 Aug 31 11:17 19.c
-rw-r--r--@ 1 kunalagarwal  staff   1735 Aug 19 11:59 2.cpp
-rw-r--r--@ 1 kunalagarwal  staff   2933 Aug 31 15:26 20.c
-rw-r--r--@ 1 kunalagarwal  staff   1358 Aug 31 15:27 21.c
-rw-r--r--@ 1 kunalagarwal  staff   2276 Aug 31 15:28 22.c
-rw-r--r--@ 1 kunalagarwal  staff    750 Aug 31 15:30 23.c
-rw-r--r--@ 1 kunalagarwal  staff    875 Aug 31 00:18 24.c
-rw-r--r--@ 1 kunalagarwal  staff   2560 Aug 31 15:32 25.c
-rwxr-xr-x@ 1 kunalagarwal  staff  33456 Aug 29 17:05 26
-rw-r--r--@ 1 kunalagarwal  staff   1185 Aug 31 00:18 26.c
-rwxr-xr-x@ 1 kunalagarwal  staff  33464 Aug 29 12:36 26.out
-rw-r--r--@ 1 kunalagarwal  staff    600 Aug 31 15:34 27a.c
-rw-r--r--@ 1 kunalagarwal  staff    532 Aug 31 00:18 27b.c
-rw-r--r--@ 1 kunalagarwal  staff    674 Aug 31 15:37 27c.c
-rw-r--r--@ 1 kunalagarwal  staff    625 Aug 31 15:38 27d.c
-rw-r--r--@ 1 kunalagarwal  staff    575 Aug 30 10:37 27e.c
-rw-r--r--@ 1 kunalagarwal  staff   1343 Aug 31 00:18 28.c
-rw-r--r--@ 1 kunalagarwal  staff    849 Aug 31 00:18 29.c
-rwxr-xr-x  1 kunalagarwal  staff  16832 Aug 18 22:31 2A
-rw-r--r--@ 1 kunalagarwal  staff    427 Aug 31 00:18 2A.c
-rw-r--r--@ 1 kunalagarwal  staff   1252 Aug 31 00:18 3.c
-rw-r--r--@ 1 kunalagarwal  staff   1438 Aug 30 09:52 30.c
-rw-r--r--@ 1 kunalagarwal  staff   1729 Aug 31 14:36 4.c
-rw-r--r--@ 1 kunalagarwal  staff    640 Aug 31 14:38 5.c
-rwxr-xr-x  1 kunalagarwal  staff  33904 Aug 19 11:59 6
-rw-r--r--@ 1 kunalagarwal  staff   2494 Aug 31 14:57 6.c
drwxr-xr-x  3 kunalagarwal  staff     96 Aug 19 11:59 6.dSYM
-rw-r--r--@ 1 kunalagarwal  staff   2300 Aug 31 15:14 7a.c
-rw-r--r--@ 1 kunalagarwal  staff   1028 Aug 31 15:01 8.c
-rw-r--r--  1 kunalagarwal  staff   1279 Aug 21 22:21 9.c
-rw-r--r--@ 1 kunalagarwal  staff    201 Aug 29 16:53 a.c
-rwxr-xr-x@ 1 kunalagarwal  staff  33608 Aug 31 15:39 a.out
-rwxr-xr-x@ 1 kunalagarwal  staff  33456 Aug 29 17:06 b
-rw-r--r--@ 1 kunalagarwal  staff     62 Aug 31 15:28 example.txt
-rwxr-xr-x@ 1 kunalagarwal  staff      0 Aug 18 23:21 existingfile.txt
-rw-r--r--@ 1 kunalagarwal  staff    311 Aug 31 15:13 f1.txt
-rw-r--r--@ 1 kunalagarwal  staff   1654 Aug 19 21:31 f2.txt
prw-r--r--@ 1 kunalagarwal  staff      0 Aug 30 22:01 fifo_name
-rw-r--r--@ 1 kunalagarwal  staff      0 Aug 19 21:37 file_1.txt
-rw-r--r--@ 1 kunalagarwal  staff      0 Aug 19 21:37 file_2.txt
-rw-r--r--@ 1 kunalagarwal  staff      0 Aug 19 21:37 file_3.txt
-rw-r--r--@ 1 kunalagarwal  staff      0 Aug 19 21:37 file_4.txt
-rw-r--r--@ 1 kunalagarwal  staff      0 Aug 19 21:37 file_5.txt
-rw-r--r--@ 3 kunalagarwal  staff    300 Aug 31 15:19 hard_link_name
-rw-r--r--@ 1 kunalagarwal  staff     94 Aug 29 23:12 hello.c
-rwxr-xr-x@ 1 kunalagarwal  staff  33432 Aug 29 23:12 hello.out
-rw-r--r--@ 3 kunalagarwal  staff    300 Aug 31 15:19 hi.txt
prw-r--r--@ 1 kunalagarwal  staff      0 Aug 30 21:54 kunal_fifo
-rw-r--r--@ 3 kunalagarwal  staff    300 Aug 31 15:19 kunal_hard_link
lrwxr-xr-x@ 1 kunalagarwal  staff      6 Aug 30 21:54 kunal_soft_link -> hi.txt
-rwxr-xr-x@ 1 kunalagarwal  staff      0 Aug 31 14:35 myfile.txt
-rw-r--r--@ 1 kunalagarwal  staff    150 Aug 30 22:12 records.txt
-rwxr-xr-x@ 1 kunalagarwal  staff  33464 Aug 29 17:02 run_program
lrwxr-xr-x@ 1 kunalagarwal  staff      6 Aug 30 22:01 soft_link_name -> hi.txt
-rw-r--r--  1 kunalagarwal  staff    455 Aug 22 21:41 temp.c
-rw-r--r--@ 1 kunalagarwal  staff    114 Aug 31 15:07 testfile.txt
-rw-r--r--@ 1 kunalagarwal  staff      1 Aug 31 15:24 ticket.txt

./6.dSYM:
total 0
drwxr-xr-x  4 kunalagarwal  staff  128 Aug 19 11:59 Contents

./6.dSYM/Contents:
total 8
-rw-r--r--  1 kunalagarwal  staff  630 Aug 19 11:59 Info.plist
drwxr-xr-x  4 kunalagarwal  staff  128 Aug 19 11:59 Resources

./6.dSYM/Contents/Resources:
total 0
drwxr-xr-x  3 kunalagarwal  staff  96 Aug 19 11:59 DWARF
drwxr-xr-x  3 kunalagarwal  staff  96 Aug 19 11:59 Relocations

./6.dSYM/Contents/Resources/DWARF:
total 24
-rw-r--r--  1 kunalagarwal  staff  9500 Aug 19 11:59 6

./6.dSYM/Contents/Resources/Relocations:
total 0
drwxr-xr-x  3 kunalagarwal  staff  96 Aug 19 11:59 aarch64

./6.dSYM/Contents/Resources/Relocations/aarch64:
total 8
-rw-r--r--  1 kunalagarwal  staff  399 Aug 19 11:59 6.yml
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % */