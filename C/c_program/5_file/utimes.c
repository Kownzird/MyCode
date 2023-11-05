#include <sys/types.h>
#include <utime.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


#define MY_FILE "./utimes.c"

int main(void){
    struct timeval tmval_arr[2];
    time_t cur_sec;
    int ret;
    int i;

    /* 检查文件是否存在 */
    ret = access(MY_FILE, F_OK);
    if (-1 == ret) {
        printf("Error: %s file does not exist!\n", MY_FILE);
        exit(-1);
    }

    /* 获取当前时间 */
    time(&cur_sec);
    for(i=0; i<2; i++){
        tmval_arr[i].tv_sec = cur_sec;
        tmval_arr[i].tv_usec = 0;
    }

    /* 修改文件时间戳 */
    ret = utimes(MY_FILE, tmval_arr);
    if(-1==ret){
        perror("utimes error");
        exit(-1);
    }
    
    exit(0);
}