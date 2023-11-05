#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    struct tm local_t;
    char tm_str[100]={0};
    time_t sec;

    sec = time(NULL);
    if(-1 == sec){
        perror("time error");
        exit(-1);
    }

    localtime_r(&sec, &local_t);
    asctime_r(&local_t, tm_str);
    printf("本地时间：%s\n",tm_str);

    exit(0);
}