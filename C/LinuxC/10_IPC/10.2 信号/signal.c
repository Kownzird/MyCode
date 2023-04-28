#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


void signal_handler(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("Child process has finished its task\n");
    }
}

int main()
{
    pid_t pid;
    int status;

    // 安装信号处理函数
    signal(SIGUSR1, signal_handler);

    // 创建子进程
    pid = fork();
    if (pid == 0)
    {
        // 子进程执行任务
        sleep(5);
        // 发送信号告知父进程自己已经完成任务
        kill(getppid(), SIGUSR1);
        exit(0);
    }
    else if (pid > 0)
    {
        // 父进程等待子进程完成任务
        wait(&status);
        if (WIFEXITED(status))
        {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
    }
    else
    {
        // 创建子进程失败
        perror("fork");
        exit(1);
    }

    return 0;
}
