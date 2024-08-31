//Kunal Agarwal MT2024083
/*8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.*/
#include <stdio.h>

int main() {
    // File pointer
    FILE *file;
    
    // Buffer to hold each line read from the file
    char line[256];

    // Open the file in read-only mode ("r")
    file = fopen("f2.txt", "r");
    // fopen(filename,mode);
    // Check if the file was successfully opened
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read each line from the file until the end of file (EOF) is reached
    while (fgets(line, sizeof(line), file)) {
        //fgets(char * restrict str, int size, FILE * restrict stream);
        //Upon successful completion, fgets() and gets() return a pointer to the string.
        // Display the line that was read
        printf("%s", line);
        char ch;

       ch = getchar();
    }

    // Close the file
    fclose(file);

    return 0;
}

/*Output:
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 8.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
//STDIN: Refers to standard input, which is the default source of input data for a program. 

//By default, it is associated with the keyboard input (file descriptor 0).

//STDOUT: Refers to standard output, which is the default destination for output data from a program. */