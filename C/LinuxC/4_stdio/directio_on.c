/** 使用宏定义 O_DIRECT 需要在程序中定义宏_GNU_SOURCE
** 不然提示 O_DIRECT 找不到 **/
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


/** 定义一个用于存放数据的 buf，起始地址以 4096 字节进行对齐 **/
static char buf[8192] __attribute((aligned (4096)));

int main(void){
    int fd;
    int count;

    /* 打开文件 */
    fd = open("./test_file",O_WRONLY | O_CREAT | O_TRUNC | O_DIRECT,0664);
    if (0 > fd) {
        perror("open error");
        exit(-1);
    }

    /* 写文件 */
    count = 10000;
    while(count--) {
        if (4096 != write(fd, buf, 4096)) {
            perror("write error");
            exit(-1);
        }
    }

    /* 关闭文件退出程序 */
    close(fd);
    exit(0);
}