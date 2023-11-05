#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int fd1, fd2, fd3;
    int ret;
    
    fd1 = open("./test_file",O_WRONLY|O_CREAT);
    if(-1==fd1){
        perror("open error");
        exit(-1);
    }

    fd2 = open("./test_file",O_WRONLY|O_CREAT);
    if(-1==fd2){
        perror("open error");
        goto err1;
    }

    fd3 = open("./test_file",O_WRONLY|O_CREAT);
    if(-1==fd3){
        perror("open error");
        goto err2;
    }

    printf("fd1=%d fd2=%d fd3=%d\n",fd1,fd2,fd3);
    close(fd3);

    ret = 0;
err2:
    close(fd2);

err1:
    close(fd1);
    exit(ret);
}