// Kunal Agarwal MT2024083
/*7. Write a program to copy file1 into file2 ($cp file1 file2).*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    // argc (argument count) is an integer representing the number of command-line arguments passed to the program.
    //argv (argument vector) is an array of strings (character pointers). Each element of this array is a command-line argument.

    if (argc != 3) {
        //the count should be exactly equal to 3(program name,source file,destination file)

        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
       //fprintf: This function is used to print formatted text to a specified output stream.
       //The first argument to fprintf is the stream where you want the output to go, in this case, stderr.
        return 1; 
    }

    // Open the source file for reading
    FILE *sourceFile = fopen(argv[1], "r");
    //fopen(filename, mode);
   //fopen: This function is used to open a file. It returns a pointer to a FILE object that represents the file.
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    // Open the destination file for writing
    FILE *destFile = fopen(argv[2], "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        //we must have to close the sourcefile before returning
        return 1;
    }

    // Buffer to hold data
    char buffer[1024];
    size_t bytesRead;

    // Read from source and write to destination in chunks
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
       //the fread function reads a specified number of bytes from a file into memory.
       //size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
       // It returns the total number of bytes successfully read
       //it will be less than count if error or end of the file 
        fwrite(buffer, 1, bytesRead, destFile);
        //The fwrite function writes a specified number of bytes from memory to a file.
        //size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);

    }

    // Close both files
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
