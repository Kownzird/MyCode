#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    struct tm local_t;
    char tm_str[100] = {0};
    time_t sec;

    /* 获取时间 */
    sec = time(NULL);
    if (-1 == sec) {
        perror("time error");
        exit(-1);
    }

    localtime_r(&sec, &local_t);
    strftime(tm_str, sizeof(tm_str), "%Y-%m-%d %A %H:%M:%S", &local_t);
    printf("本地时间: %s\n", tm_str);
    
    exit(0);
}