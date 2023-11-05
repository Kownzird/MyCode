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
            printf("子进程<%d>被创建\n", getpid());
            sleep(1);
            printf("子进程结束\n");
            _exit(0);
        default:
            /* 父进程 */
            break;
    }
    
    for ( ; ; )
        sleep(1);
    exit(0);
}