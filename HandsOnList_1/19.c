//Kunal Agarwal MT2024083
/*19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.*/
#include <stdio.h>
#include <unistd.h>//for getpid();
#include <stdint.h>//defines integer types with specific widths,like uint64_t
#include <mach/mach_time.h>//provides access to high-resolution timing functions specific to MACos

uint64_t get_time_ns() {
    //uint64_t is a data type in C that represents an unsigned 64-bit integer.
    static mach_timebase_info_data_t timebase;
    /*mach_timebase_info_data_t is a structure that holds timebase information with two fields: numer (numerator) and denom (denominator). This structure is used to convert the machine's absolute time to nanoseconds.*/
   //static ensures that  the variable is only initialised once
    if (timebase.denom == 0) {
        //if the denom feild is 0 then it means that the timebase information has not been initialised yet
        mach_timebase_info(&timebase);
        /*This system call populates the timebase structure with the appropriate values for converting the machine's absolute time to nanoseconds. The numerator (numer) and denominator (denom) values are used to scale the absolute time correctly.*/
    }
    uint64_t time = mach_absolute_time();
    /*mach_absolute_time(): This function retrieves the current time in a platform-specific unit*/
    return time * timebase.numer / timebase.denom;
    /*The absolute time obtained is multiplied by the numerator (numer) and divided by the denominator (denom) to convert it to nanoseconds. This conversion is necessary because the mach_absolute_time() function does not return time directly in nanoseconds.*/
}

int main() {
    uint64_t start, end;// variables to store the start and end times in ns
    pid_t pid;

    start = get_time_ns();  // Get time before calling getpid
    pid = getpid();         // Execute the getpid system call
    end = get_time_ns();    // Get time after calling getpid

    printf("Process ID: %d\n", pid);
    printf("Start time: %llu ns\n", start);
    printf("End time: %llu ns\n", end);
    printf("Time taken by getpid: %llu ns\n", end - start);

    return 0;
}

/*Output
Kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 19.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
Process ID: 88009
Start time: 83381929592500 ns
End time: 83381929592583 ns
Time taken by getpid: 83 ns*/