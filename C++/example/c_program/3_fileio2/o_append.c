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
    char buf[4];
    
    //O_APPEND 标志， 调用 open 函数打开文件，
    //当每次使用 write()函数对文件进行写操作时，都会自动把文件当前位置偏移量移动到文件末尾
    fd = open("./test_file",O_WRONLY|O_APPEND);
    if(-1==fd){
        perror("open error");
        exit(-1);
    }

    memset(buf,0xff,sizeof(buf));
    ret = write(fd,buf,sizeof(buf));
    if(-1==ret){
        perror("write error");
        goto err;
    }

    ret = 0;
err:
    close(fd);
    exit(ret);
}