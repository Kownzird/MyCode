#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// 获取文件的 inode 节点编号以及文件大小， 并将它们打印出来
int main(void){
    struct stat file_stat;
    int ret;

    ret = stat("./file_test1.c", &file_stat);
    if(-1==ret){
        perror("stat error");
        exit(-1);
    }

    /* 打印文件大小和 inode 编号 */
    printf("file size: %ld size\n",file_stat.st_size);
    printf("inode number: %ld\n",file_stat.st_ino);

    exit(0);
}