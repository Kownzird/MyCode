#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = getpid(); //获取本进程 pid
    printf("本进程的 PID 为: %d\n", pid);

    pid = getppid(); //获取父进程 pid
    printf("父进程的 PID 为: %d\n", pid);

    exit(0);
}