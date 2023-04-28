#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int fd;
    int ret;
    char buf[1024];

    fd = open("./hole_file", O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (-1 == fd) {
        perror("open error");
        exit(-1);
    }

    /* 将文件读写位置移动到偏移文件头 4096 个字节(4K)处 */
    ret = lseek(fd,4096,SEEK_SET);
    if(-1==ret){
        perror("lseek error");
        goto err;
    }

    /* 初始化 buffer 为 0xFF */
    memset(buf,0xff,1024);

    /* 循环写入 4 次，每次写入 1K */
    for(int i=0; i<4; i++){
        ret = write(fd,buf,1024);
        if(-1==ret){
            perror("write error");
            goto err;
        }
    }

    ret = 0;

err:
    close(fd);
    exit(ret);
}