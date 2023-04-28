#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex1, mutex2;

void *thread_func1(void *arg)
{
    pthread_mutex_lock(&mutex1);
    printf("Thread 1 get mutex1, wait for mutex2...\n");
    sleep(1);

    pthread_mutex_lock(&mutex2);
    printf("Thread 1 get mutex2, do something...\n");
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

void *thread_func2(void *arg)
{
    pthread_mutex_lock(&mutex2);
    printf("Thread 2 get mutex2, wait for mutex1...\n");
    sleep(1);

    pthread_mutex_lock(&mutex1);
    printf("Thread 2 get mutex1, do something...\n");
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    return NULL;
}

int main(void)
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    if (pthread_create(&thread1, NULL, &thread_func1, NULL) != 0) {
        fprintf(stderr, "Failed to create thread1.\n");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&thread2, NULL, &thread_func2, NULL) != 0) {
        fprintf(stderr, "Failed to create thread2.\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);
    return 0;
}
