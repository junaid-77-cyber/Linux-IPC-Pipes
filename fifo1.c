#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char *fifo_path = "/tmp/myfifo";
    char write_msg[] = "Message from Writer process";

    // Create FIFO if it doesn’t exist
    mkfifo(fifo_path, 0666);

    fd = open(fifo_path, O_WRONLY);
    write(fd, write_msg, strlen(write_msg) + 1);
    close(fd);

    return 0;
}
