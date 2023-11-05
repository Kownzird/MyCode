#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int fd1,fd2;
    int ret;

    /* 打开文件 test_file */
    fd1 = open("./test_file",O_RDONLY);
    if(-1==fd1){
        perror("open error");
        exit(-1);
    }

    /* 使用 fcntl 函数复制一个文件描述符 */
    fd2 = fcntl(fd1, F_DUPFD, 100);
    if(-1==fd2){
        perror("fcntl error");
        goto err;
    }

    printf("fd1=%d fd2=%d\n",fd1,fd2);
    ret = 0;

    close(fd2);
err:
    close(fd1);

    return ret;
}