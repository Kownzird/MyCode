#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(void)
{
    int status;
    int ret;
    int i;

    /* 循环创建 3 个子进程 */
    for (i = 1; i <= 3; i++) {
        switch (fork()) {
            case -1:
                perror("fork error");
                exit(-1);
            case 0:
                /* 子进程 */
                printf("子进程<%d>被创建\n", getpid());
                sleep(i);
                _exit(i);
            default:
                /* 父进程 */
                break;
        }
    }

    sleep(1);
    printf("~~~~~~~~~~~~~~\n");
    for (i = 1; i <= 3; i++) {
        ret = wait(&status);
        if (-1 == ret) {
            if (ECHILD == errno) {
                printf("没有需要等待回收的子进程\n");
                exit(0);
            }
            else {
                perror("wait error");
                exit(-1);
            }
        }
        printf("回收子进程<%d>, 终止状态<%d>\n", ret, WEXITSTATUS(status));
    }
    exit(0);
}