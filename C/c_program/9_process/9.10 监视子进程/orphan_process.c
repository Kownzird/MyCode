#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    /* 创建子进程 */
    switch (fork()) {
        case -1:
            perror("fork error");
            exit(-1);
        case 0:
            /* 子进程 */
            printf("子进程<%d>被创建, 父进程<%d>\n", getpid(), getppid());
            sleep(3); //休眠 3 秒钟等父进程结束
            printf("父进程<%d>\n", getppid());//再次获取父进程 pid
            _exit(0);
        default:
            /* 父进程 */
            break;
    }
    
    sleep(1);//休眠 1 秒
    printf("父进程结束!\n");
    exit(0);
}