#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <netinet/in.h>

void* handle_client(void* arg) {
    int c = *(int*)arg;
    char buffer[100];
    read(c, buffer, sizeof(buffer));
    write(c, "Hello\n", 6);
    close(c);
    return NULL;
}

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;  // Correctly set sin_family
    addr.sin_port = htons(8080);  // Set sin_port using htons()
    addr.sin_addr.s_addr = INADDR_ANY;  // Set sin_addr to INADDR_ANY

    bind(s, (struct sockaddr*)&addr, sizeof(addr));
    listen(s, 5);

    while (1) {
        int c = accept(s, NULL, NULL);
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, &c);
        pthread_detach(tid);
    }
}
