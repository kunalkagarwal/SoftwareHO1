//Kunal Agarwal MT2024083
/*13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t target_pid;

    printf("Enter the PID of the process to stop: ");
    scanf("%d", &target_pid);
    
    // Send SIGSTOP to the specified process
    if (kill(target_pid, SIGSTOP) == -1) {
        perror("kill");
        exit(EXIT_FAILURE);
    }

    printf("Sent SIGSTOP to process %d.\n", target_pid);
    return 0;
}
