#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define LOCK_FILE "./singleton_filelock.pid"

int main(void){
    char str[20] = {0};
    int fd;

    /* 打开 lock 文件，如果文件不存在则创建 */
    fd = open(LOCK_FILE, O_WRONLY | O_CREAT, 0666);
    if (-1 == fd) {
        perror("open error");
        exit(-1);
    }

    /* 以非阻塞方式获取文件锁 */
    //LOCK_SH: 共享锁，可以被其他进程也加共享锁访问，但不能被写入锁访问。
    //LOCK_EX: 独占锁，只能被持有锁的进程访问并加锁，其他进程无法访问所加锁的区域。
    //LOCK_UN: 解锁指定区域。
    //LOCK_NB: 非阻塞锁，在文件已经被锁住的情况下不会阻塞等待锁的释放而立即返回，并返回错误信息。

    if (-1 == flock(fd, LOCK_EX | LOCK_NB)) {
        fputs("不能重复执行该程序!\n", stderr);
        close(fd);
        exit(-1);
    }

    puts("程序运行中...");
    ftruncate(fd, 0); //将文件长度截断为 0
    sprintf(str, "%d\n", getpid());
    write(fd, str, strlen(str));//写入 pid

    for ( ; ; )
        sleep(1);
    exit(0);
}