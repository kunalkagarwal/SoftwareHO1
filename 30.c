// Kunal Agarwal MT2024083
// Write a program to run a script at a specific time using a Daemon process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Function to turn the current process into a daemon
void daemonize() {
    pid_t pid;

    // Step 1: Fork the parent process to create a new child process
    pid = fork();

    // If fork() fails, exit with failure status
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // If fork() succeeds, the parent process exits to let the child run independently
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // Step 2: Set the file mode creation mask to 0, so the daemon has full access to any files it creates
    umask(0);

    // Step 3: Create a new session and set the child process as the session leader
    if (setsid() < 0) {
        perror("setsid");
        exit(EXIT_FAILURE);
    }

    // Step 4: Fork again to ensure the daemon is no longer a session leader
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // If fork() succeeds, the first child process exits, leaving the second child as the daemon
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // Step 5: Change the current working directory to root to avoid locking a directory in the filesystem
    if (chdir("/") < 0) {
        perror("chdir");
        exit(EXIT_FAILURE);
    }

    // Step 6: Close all open file descriptors inherited from the parent process
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Step 7: Redirect standard file descriptors to /dev/null to prevent any accidental read/write operations
    open("/dev/null", O_RDONLY); // Redirect stdin
    open("/dev/null", O_WRONLY); // Redirect stdout
    open("/dev/null", O_WRONLY); // Redirect stderr
}

int main() {
    // Daemonize the current process to run in the background
    daemonize();

    // Set the specific time (hour and minute) to run the script
    int hour = 16;    // 4:00 PM
    int minute = 12;  // 12 minutes past the hour

    // Infinite loop to keep the daemon running and checking the time
    while (1) {
        // Get the current time
        time_t now = time(NULL);
        struct tm *local = localtime(&now);

        // Check if the current time matches the target time
        if (local->tm_hour == hour && local->tm_min == minute) {
            // If the time matches, execute the specified script
            system("/Users/kunalagarwal/Desktop/30.sh");

            // Sleep for 60 seconds to avoid running the script multiple times in the same minute
            sleep(60);
        }

        // Sleep for 1 second before checking the time again
        sleep(1);
    }

    return 0;
}
