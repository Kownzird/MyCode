#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define LOCK_FILE "./singleton.lock"

static void delete_file(void){
    remove(LOCK_FILE);
}

int main(void){
    /* 打开文件 */
    //关键在于O_EXCL标签，存在O_EXCL时，程序要正常执行则不允许存在LOCK_FILE文件
    // int fd = open(LOCK_FILE, O_RDONLY | O_CREAT , 0666);
    int fd = open(LOCK_FILE, O_RDONLY | O_CREAT | O_EXCL, 0666);
    if (-1 == fd) {
        fputs("不能重复执行该程序!\n", stderr);
        exit(-1);
    }

    /* 注册进程终止处理函数 */
    if (atexit(delete_file)){
        exit(-1);
    }
    
    puts("程序运行中...");

    sleep(10);

    puts("程序结束");
    
    close(fd); //关闭文件
    exit(0);
}