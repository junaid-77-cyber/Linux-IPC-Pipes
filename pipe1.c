#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    char *fifo_path = "/tmp/myfifo";
    char read_msg[100];

    mkfifo(fifo_path, 0666);

    fd = open(fifo_path, O_RDONLY);
    read(fd, read_msg, sizeof(read_msg));
    printf("Reader received message: %s\n", read_msg);
    close(fd);

    return 0;
}
