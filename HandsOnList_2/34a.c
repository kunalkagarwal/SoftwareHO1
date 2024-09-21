//Kunal Agarwal MT2024083
/*34. Write a program to create a concurrent server.
a. use fork
b. use pthread_create*/
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;  // Explicitly set sin_family
    addr.sin_port = htons(8080); // Set the port using htons
    addr.sin_addr.s_addr = INADDR_ANY; // Use INADDR_ANY for the address

    bind(s, (struct sockaddr*)&addr, sizeof(addr));
    listen(s, 5);

    while (1) {
        int c = accept(s, NULL, NULL);
        if (fork() == 0) { 
            char buffer[100];
            read(c, buffer, sizeof(buffer));
            write(c, "Hello\n", 6);
            close(c);
            return 0; 
        }
        close(c);
    }
}
