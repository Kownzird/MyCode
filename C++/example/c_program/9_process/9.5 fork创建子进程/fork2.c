#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    pid = fork();
    switch (pid) {
        case -1:
            perror("fork error");
            exit(-1);
        case 0:
            printf("这是子进程打印信息\n");
            printf("%d\n", pid);
            _exit(0);
        default:
            printf("这是父进程打印信息\n");
            printf("%d\n", pid);
            exit(0);
    }
}