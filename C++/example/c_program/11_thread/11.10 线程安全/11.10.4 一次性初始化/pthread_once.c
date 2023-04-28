#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static pthread_once_t once = PTHREAD_ONCE_INIT;
static int nums[5] = {0, 1, 2, 3, 4};

static void initialize_once(void){
    printf("initialize_once 被执行: 线程 ID<%lu>\n", pthread_self());
}

static void func(void){
    pthread_once(&once, initialize_once);//执行一次性初始化函数
    printf("函数 func 执行完毕.\n");
}

static void *thread_start(void *arg){
    printf("线程%d 被创建: 线程 ID<%lu>\n", *((int *)arg), pthread_self());
    func(); //调用函数 func
    pthread_exit(NULL); //线程终止
}


int main(void){
    pthread_t tid[5];
    int j;

    /* 创建 5 个线程 */
    for (j = 0; j < 5; j++)
        pthread_create(&tid[j], NULL, thread_start, &nums[j]);

    /* 等待线程结束 */
    for (j = 0; j < 5; j++)
        pthread_join(tid[j], NULL);//回收线程

    exit(0);
}