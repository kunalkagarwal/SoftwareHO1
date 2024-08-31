//Kunal Agarwal MT2024083
/*2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>


int main() {
    
    while (1) {

       sleep(15); // Wait 10 seconds before repeating
    }

    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ps aux | grep a.out
kunalagarwal     51648   0.0  0.0 410220144    528   ??  S    Thu11PM   0:01.91 ./a.out
kunalagarwal     98663   0.0  0.0 410199728   1152 s060  S+    3:52PM   0:00.00 grep a.out
kunalagarwal     96429   0.0  0.0 410068576    464 s060  SN    3:46PM   0:00.00 ./a.out*/