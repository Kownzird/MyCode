#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static void wait_child(int sig){
    /* 替子进程收尸 */
    printf("父进程回收子进程\n");
    //直至 waitpid()返回 0，表明再无僵尸进程存在；或者返回-1，表明有错误发生
    while (waitpid(-1, NULL, WNOHANG) > 0)
        continue;
    printf("父进程已经回收子进程\n");
}

int main(void){
    struct sigaction sig = {0};

    /* 为 SIGCHLD 信号绑定处理函数 */
    sigemptyset(&sig.sa_mask);
    sig.sa_handler = wait_child;
    sig.sa_flags = 0;

    if (-1 == sigaction(SIGCHLD, &sig, NULL)) {
        perror("sigaction error");
        exit(-1);
    }

    /* 创建子进程 */
    for(int i=1; i<=5; i++){
        switch (fork()) {
            case -1:
                perror("fork error");
                exit(-1);
            case 0:
                /* 子进程 */
                printf("子进程<%d>被创建\n", getpid());
                sleep(i);
                printf("子进程结束\n");
                _exit(0);
            default:
                /* 父进程 */
                break;
        }
    }
    
    sleep(1);
    for(;;){
        printf("父进程执行中...\n");
        sleep(1);
    }
    exit(0);
}