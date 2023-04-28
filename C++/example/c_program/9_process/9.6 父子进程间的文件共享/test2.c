#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// 父、子各自打开同一个文件实现文件共享
int main(void)
{
    pid_t pid;
    int fd;
    int i;
    pid = fork();
    switch (pid) {
        case -1:
            perror("fork error");
            exit(-1);
        case 0:
            /* 子进程 */
            fd = open("./test.txt", O_WRONLY);
            if (0 > fd) {
                perror("open error");
                _exit(-1);
            }
            for (i = 0; i < 4; i++) //循环写入 4 次
                write(fd, "1122", 4);
            close(fd);
            _exit(0);
        default:
            /* 父进程 */
            fd = open("./test.txt", O_WRONLY);
            if (0 > fd) {
                perror("open error");
                exit(-1);
            }
            for (i = 0; i < 4; i++) //循环写入 4 次
                write(fd, "AABB", 4);
            close(fd);
            exit(0);
    }
}