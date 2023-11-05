#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096
#define READ_FILE "./rfile"
#define WRITE_FILE "./wfile"
static char buf[BUF_SIZE];

int main(void){
    int rfd, wfd;
    size_t size;

    /* 打开源文件 */
    rfd = open(READ_FILE, O_RDONLY);
    if (0 > rfd) {
        perror("open error");
        exit(-1);
    }
    /* 打开目标文件 */
    wfd = open(WRITE_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (0 > wfd) {
        perror("open error");
        exit(-1);
    }

    /* 拷贝数据 */
    while(0 < (size = read(rfd, buf, BUF_SIZE)))
    write(wfd, buf, size);

    /* 对目标文件执行 fsync 同步 */
    fsync(wfd);
    // fdatasync(wfd);

    /* 关闭文件退出程序 */
    close(rfd);
    close(wfd);
    exit(0);
}