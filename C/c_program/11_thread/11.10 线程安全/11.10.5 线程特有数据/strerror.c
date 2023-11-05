#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

#ifndef _SYS_NERR
#define _SYS_NERR 1000
#endif

char *_sys_errlist[] = {
    "Error 0",
    "Error 1",
    "Error 2"
};

#define MAX_ERROR_LEN 256
static char buf[MAX_ERROR_LEN];

/**********************************
* 为了避免与库函数 strerror 重名
* 这里将其改成 my_strerror
**********************************/
static char *my_strerror(int errnum){
    if (errnum < 0 || errnum >= _SYS_NERR || NULL == _sys_errlist[errnum])
        snprintf(buf, MAX_ERROR_LEN, "Unknown error %d", errnum);
    else {
        strncpy(buf, _sys_errlist[errnum], MAX_ERROR_LEN - 1);
        buf[MAX_ERROR_LEN - 1] = '\0';//终止字符
    }
    return buf;
}

static void *thread_start(void *arg){
    char *str = my_strerror(2); //获取错误编号为 2 的错误描述信息
    printf("子线程: str (%p) = %s\n", str, str);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    pthread_t tid;
    char *str = NULL;
    int ret;

    str = my_strerror(1); //获取错误编号为 1 的错误描述信息
    printf("主线程创建线程前: str (%p) = %s\n", str, str);

    /* 创建子线程 */
    if (ret = pthread_create(&tid, NULL, thread_start, NULL)) {
        fprintf(stderr, "pthread_create error: %d\n", ret);
        exit(-1);
    }

    /* 等待回收子线程 */
    if (ret = pthread_join(tid, NULL)) {
        fprintf(stderr, "pthread_join error: %d\n", ret);
        exit(-1);
    }

    printf("主线程: str (%p) = %s\n", str, str);
    exit(0);
}