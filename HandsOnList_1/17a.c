//KunalAgarwal  MT2024083
//Q17a.Write a program to simulate online ticket reservation. Implement write lock
// Write a program to open a file, store a ticket number and exit.


#include <stdio.h>//this library allows the use of fopen

int main() {
    FILE *file = fopen("ticket.txt", "w");
    //FILE *fopen(const char *filename, const char *mode);
    //returns the pointer to a file object
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int ticket_number = 1;  // Initial ticket number
    fprintf(file, "%d", ticket_number);
    //int fprintf(FILE *stream, const char *format, ...);
    //fprintf allows us to specify the file where the output should be written
    fclose(file);
     //closes the file associated with file(ticket.txt)
    printf("Ticket number %d stored successfully.\n", ticket_number);
    return 0;
}
/*kunalagarwal@Kunals-MacBook-Air software systems handson 1 % cc 17a.c
kunalagarwal@Kunals-MacBook-Air software systems handson 1 % ./a.out
Ticket number 1 stored successfully.*/