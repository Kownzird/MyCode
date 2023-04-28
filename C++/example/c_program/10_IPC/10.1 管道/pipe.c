#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define MSGSIZE 16

//无名管道
int main() {
    char msg[MSGSIZE];  // 用于存储消息的缓冲区
    int p[2], pid, nbytes;  // p[0]和p[1]为管道读写端，pid保存fork返回值，nbytes保存从管道读取的字节数
    if (pipe(p) < 0) {  // 创建管道，如果失败则退出程序
        exit(-1);
    }
    if ((pid = fork()) > 0) {  // 在父进程中
        printf("Enter a string: ");
        scanf("%s", msg);
        close(p[0]);  // 关闭读取管道
        write(p[1], msg, strlen(msg)+1);  // 往管道中写入数据
        close(p[1]);  // 关闭写入管道
    } else if (pid == 0) {  // 在子进程中
        close(p[1]);  // 关闭写入管道
        nbytes = read(p[0], msg, MSGSIZE);  // 从管道中读取数据到缓冲区
        printf("Received string: %s\nNumber of bytes received: %d\n", msg, nbytes-1);
        close(p[0]);  // 关闭读取管道
    } else {  // 如果fork失败
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    }
    return 0;
}
