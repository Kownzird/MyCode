#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid;
    int num = 100;
    
    pid = vfork();
    switch (pid) {
        case -1:
            perror("vfork error");
            exit(-1);
        case 0:
            /* 子进程 */
            printf("子进程打印信息\n");
            printf("子进程打印 num: %d\n", num);
            _exit(0);
        default:
            /* 父进程 */
            printf("父进程打印信息\n");
            printf("父进程打印 num: %d\n", num);
            exit(0);
    }
}
