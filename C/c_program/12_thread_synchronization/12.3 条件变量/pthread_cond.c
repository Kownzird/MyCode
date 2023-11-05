#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
static pthread_mutex_t mutex; //定义互斥锁
static pthread_cond_t cond; //定义条件变量
static int g_avail = 0; //全局共享资源

/* 消费者线程 */
static void *consumer_thread(void *arg){
    for ( ; ; ) {
        pthread_mutex_lock(&mutex);//上锁
        while (0 >= g_avail)
            //调用 pthread_cond_wait()后线程阻塞并解锁互斥锁  
            pthread_cond_wait(&cond, &mutex);//等待条件满足
        while (0 < g_avail)
            g_avail--; //消费
        pthread_mutex_unlock(&mutex);//解锁
    }
    return (void *)0;
}

/* 主线程（生产者） */
int main(int argc, char *argv[]){
    pthread_t tid;
    int ret;

    /* 初始化互斥锁和条件变量 */
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

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
        pthread_cond_signal(&cond);//向条件变量发送信号
    }
    exit(0);
}