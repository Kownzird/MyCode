#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    printf("创建有名管道。\n");
    if (mkfifo("./myfifo", 0666) == -1) {
        perror("mkfifo");
        return -1;
    }

    printf("打开管道文件\n");
    int fd = open("./myfifo", O_WRONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    for (;;) {
        char buf[1024];
        printf(">");
        fgets(buf, sizeof(buf) * sizeof(buf[0]), stdin);
        if (!strcmp(buf, "quit\n")) {
            break;
        }
        
        printf("发送数据\n");
        if (write(fd, buf, sizeof(buf) * sizeof(buf[0])) == -1) {
            perror("write");
            return -1;
        }
    }

    if (close(fd) == -1) {
        perror("close");
        return -1;
    }

    if (unlink("./myfifo") == -1) {
        perror("unlink");
        return -1;
    }
    return 0;
}
