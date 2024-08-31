//Kunal Agarwal MT2024083
/*26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)*/
#include <stdio.h>
#include <unistd.h>
//Includes the UNIX standard library, which provides access to the POSIX operating system API, including the execl function used here.

int main() {
    // Path to the executable
    char *executable = "./a.out";
// This line defines a string (char *) that holds the path to the executable program you want to run, in this case is ./a.out.
// "./a.out" refers to an executable named a.out located in the current directory (./).
    
    // Argument to pass to the executable
    char *arg = "Kunal";
// This line defines another string that holds the argument you want to pass to a.out.
// Execute the program
    execl(executable, executable, arg, (char *)NULL);
//When execl is called, it replaces the current process (the running exec_program) with the new process (a.out). If successful, execl does not return; the a.out program takes over.

    // If execl returns, an error occurred
    perror("execl failed");
    return 1;
}
