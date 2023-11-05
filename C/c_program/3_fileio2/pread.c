#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int fd;
    int ret;
    unsigned char buf[100];

    fd = open("./test_file",O_RDWR);
    if(-1==fd){
        perror("open error");
        exit(-1);
    }

    /* 使用 pread 函数读取数据(从偏移文件头 1024 字节处开始读取) */
    ret = pread(fd, buf, sizeof(buf), 1024);
    if(-1==ret){
        perror("read error");
        goto err1;
    }

    /* 获取当前位置偏移量 */
    ret = lseek(fd, 0, SEEK_SET);
    if(-1==ret){
        perror("lseek error");
        goto err1;
    }

    printf("Current offset = %d\n",ret);

    ret = 0;

err1:
    close(fd);
    exit(ret);

}