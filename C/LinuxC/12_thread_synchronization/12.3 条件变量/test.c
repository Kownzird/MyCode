#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

static pthread_mutex_t mutex;
static int g_avail = 0;

/* 消费者线程 */
static void *consumer_thread(void *arg){
    for ( ; ; ) {
        pthread_mutex_lock(&mutex);//上锁
        while (g_avail > 0)
            g_avail--; //消费
        pthread_mutex_unlock(&mutex);//解锁
    }
    return (void *)0;
}

/* 主线程（生产者） */
int main(int argc, char *argv[]){
    pthread_t tid;
    int ret;

    /* 初始化互斥锁 */
    pthread_mutex_init(&mutex, NULL);

    /* 创建新线程 */
    ret = pthread_create(&tid, NULL, consumer_thread, NULL);
    if (ret) {
        fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
        exit(-1);
    }

    for ( ; ; ) {
        pthread_mutex_lock(&mutex);//上锁
        g_avail++; //生产
        pthread_mutex_unlock(&mutex);//解锁
    }
    
    exit(0);
}