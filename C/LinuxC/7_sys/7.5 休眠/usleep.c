#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    puts("Sleep Start!");

    /* 让程序休眠 3 秒钟(3*1000*1000 微秒) */
    usleep(3 * 1000 * 1000);
    
    puts("Sleep End!");
    exit(0);
}