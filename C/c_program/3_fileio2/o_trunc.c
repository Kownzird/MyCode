#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int fd;
    
    //调用 open 函数打开文件的时候会将文件
    //原本的内容全部丢弃，文件大小变为 0
    fd = open("./test_file",O_WRONLY|O_TRUNC);
    if(-1==fd){
        perror("open error");
        exit(-1);
    }

    close(fd);
    exit(0);
}