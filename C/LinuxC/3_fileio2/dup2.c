#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int fd1, fd2;
    unsigned char buf1[4],buf2[4];
    int ret;
    
    /* 创建新文件 test_file 并打开 */
    fd1 = open("./test_file",O_RDWR|O_CREAT|O_EXCL,0777);
    if(-1==fd1){
        perror("open error");
        exit(-1);
    }

    /* 复制文件描述符 */
    fd2 = dup2(fd1,100);
    if(-1==fd2){
        perror("dup error");
        goto err1;
    }

    printf("fd1=%d fd2=%d\n",fd1,fd2);

    ret = 0;
err2:
    close(fd2);

err1:
    close(fd1);
    exit(ret);
}