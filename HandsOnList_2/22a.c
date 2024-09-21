#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd;
    mkfifo("/tmp/myfifo", 0666);
    fd = open("/tmp/myfifo", O_WRONLY);
    sleep(2); // Sleep for 2 seconds to simulate some delay
    write(fd, "Hello from writer!\n", 19);
    close(fd);
    return 0;
}