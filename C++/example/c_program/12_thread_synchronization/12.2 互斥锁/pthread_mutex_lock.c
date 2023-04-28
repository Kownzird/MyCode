#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
static pthread_mutex_t mutex;
static int g_count = 0;
static int loops;

static void *new_thread_start(void *arg){
    int loops = *((int *)arg);
    int l_count, j;
    for (j = 0; j < loops; j++) {
        pthread_mutex_lock(&mutex); //互斥锁上锁
        l_count = g_count;
        l_count++;
        g_count = l_count;
        pthread_mutex_unlock(&mutex);//互斥锁解锁
    }
    return (void *)0;
}

int main(int argc, char *argv[]){
    pthread_t tid1, tid2;
    int ret;
    
    /* 获取用户传递的参数 */
    if (2 > argc)
        loops = 10000000; //没有传递参数默认为 1000 万次
    else
        loops = atoi(argv[1]);

    /* 初始化互斥锁 */
    pthread_mutex_init(&mutex, NULL);

    /* 创建 2 个新线程 */
    ret = pthread_create(&tid1, NULL, new_thread_start, &loops);
    if (ret) {
        fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
        exit(-1);
    }

    ret = pthread_create(&tid2, NULL, new_thread_start, &loops);
    if (ret) {
        fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
        exit(-1);
    }

    /* 等待线程结束 */
    ret = pthread_join(tid1, NULL);
    if (ret) {
        fprintf(stderr, "pthread_join error: %s\n", strerror(ret));
        exit(-1);
    }

    ret = pthread_join(tid2, NULL);
    if (ret) {
        fprintf(stderr, "pthread_join error: %s\n", strerror(ret));
        exit(-1);
    }

    /* 打印结果 */
    printf("g_count = %d\n", g_count);
    exit(0);
}