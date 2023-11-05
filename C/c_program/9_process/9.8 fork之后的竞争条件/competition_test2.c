#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

static void sig_handler(int sig){
    printf("接收到信号\n");
}

int main(int argc, char *argv[]){
    struct sigaction sig={0};
    sigset_t wait_mask;

    /* 初始化信号集 */
    sigemptyset(&wait_mask);

    /* 设置信号处理方式 */
    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;
    if (-1 == sigaction(SIGUSR1, &sig, NULL)) {
        perror("sigaction error");
        exit(-1);
    }

    switch (fork()) {
        case -1:
            perror("fork error");
            exit(-1);
        case 0:
            /* 子进程 */
            printf("子进程开始执行\n");
            printf("子进程打印信息\n");
            printf("~~~~~~~~~~~~~~~\n");
            sleep(2);
            kill(getppid(), SIGINT); //发送信号给父进程、唤醒它
            _exit(0);
        default:
            /* 父进程 */
            //当调用 sigsuspend(mask) 函数时，
            //该进程将会把当前的信号屏蔽字替换为 mask 中的信号掩码，
            //然后进入挂起状态，直到收到一个未被屏蔽的信号为止。
            if (-1 != sigsuspend(&wait_mask))//挂起、阻塞
                exit(-1);
            printf("父进程开始执行\n");
            printf("父进程打印信息\n");
            exit(0);
    }
}