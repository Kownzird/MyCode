#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int fd;

    fd = open("./file1",O_RDWR);
    if(-1==fd){
        perror("open error");
        exit(-1);
    }

    /* 使用 ftruncate 将 file1 文件截断为长度 0 字节 */
    if(0 > ftruncate(fd,0)){
        perror("ftruncate fail");
        exit(-1);
    }


    /* 使用 truncate 将 file2 文件截断为长度 1024 字节 */
    if(0 > truncate("./file2",1024)){
        perror("truncate fail");
        exit(-1);
    }

    close(fd);
    exit(0);

}