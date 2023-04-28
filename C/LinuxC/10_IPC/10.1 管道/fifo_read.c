#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    printf("打开管道文件\n");
    int fd = open("./myfifo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    for (;;) {
        char buf[1024];
        printf("接收数据\n");
        ssize_t bytes = read(fd, buf, sizeof(buf) * sizeof(buf[0]));
        if (bytes == -1) {
            perror("read");
            return -1;
        }
        if (!bytes) { //当管道文件无数据可读或管道被unlike，read返回0
            break;
        }
        printf("< %s", buf);
    }
    if (close(fd) == -1) {
        perror("close");
        return -1;
    }
    return 0;
}
