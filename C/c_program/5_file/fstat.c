#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


int main(void){
    struct stat file_stat;
    int fd;
    int ret;

    /* 打开文件 */
    fd = open("./fstat.c", O_RDONLY);
    if (-1 == fd) {
        perror("open error");
        exit(-1);
    }

    /* 获取文件属性 */
    ret = fstat(fd, &file_stat);
    if (-1 == ret){
        perror("fstat error");
    }

    close(fd);
    exit(ret);
    
}
