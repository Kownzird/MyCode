#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

static void *new_thread_start(void *arg){
    int ret;

    /* 自行分离 */
    ret = pthread_detach(pthread_self());
    if (ret) {
        fprintf(stderr, "pthread_detach error: %s\n", strerror(ret));
        return NULL;
    }
    
    printf("新线程 start\n");
    sleep(2); //休眠 2 秒钟
    printf("新线程 end\n");
    pthread_exit(NULL);
}

int main(void){
    pthread_t tid;
    int ret;

    /* 创建新线程 */
    ret = pthread_create(&tid, NULL, new_thread_start, NULL);
    if (ret) {
        fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
        exit(-1);
    }
    sleep(1); //休眠 1 秒钟

    /* 等待新线程终止 */
    ret = pthread_join(tid, NULL);
    if (ret){
        fprintf(stderr, "pthread_join error: %s\n", strerror(ret));
    }
    
    pthread_exit(NULL);
}