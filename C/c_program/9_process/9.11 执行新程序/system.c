#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ret;
    if (2 > argc){
        exit(-1);
    }

    ret = system(argv[1]);
    if (-1 == ret){
        fputs("system error.\n", stderr);
    }else {
        //WIFEXITED为真:正常退出，可以获得其退出状态码
        //WEXITSTATUS(ret) 获取程序的退出状态码，如果状态码为 127，则说明无法执行指定的shell命令，这是一种异常情况
        if (WIFEXITED(ret) && (127 == WEXITSTATUS(ret))){
            fputs("could not invoke shell.\n", stderr);
        }
    }
    exit(0);
}