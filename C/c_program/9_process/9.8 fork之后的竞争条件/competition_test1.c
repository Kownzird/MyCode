#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    switch (fork()) {
        case -1:
            perror("fork error");
            exit(-1);
        case 0:
            /* 子进程 */
            printf("子进程打印信息\n");
            _exit(0);
        default:
            /* 父进程 */
            printf("父进程打印信息\n");
            exit(0);
    }
}