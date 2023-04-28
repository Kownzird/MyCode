#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
    printf("Hello world\n");
    printf("Hello world");

    //刷新标准输出 stdio 缓冲区
    // fflush(stdout);

    //关闭文件时刷新 stdio 缓冲区
    // fclose(stdout);

    //程序退出时刷新 stdout 缓冲区
    // exit(0);
    // _exit(0);

    for(;;){
        sleep(1);
    }
}