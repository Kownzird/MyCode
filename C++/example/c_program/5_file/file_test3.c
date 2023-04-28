#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 获取文件的类型， 判断此文件对于其它用户（Other） 是否具有可读可写权限
int main(void){
    struct stat file_stat;
    struct tm file_tm;
    char time_str[100];
    int ret;

    ret = stat("./file_test1.c", &file_stat);
    if(-1==ret){
        perror("stat error");
        exit(-1);
    }

    /* 打印文件最后被访问的时间 */
    localtime_r(&file_stat.st_atim.tv_sec, &file_tm);
    strftime(time_str, sizeof(time_str),"%Y-%m-%d %H:%M:%S", &file_tm);
    printf("time of last access: %s\n", time_str);

    /* 打印文件内容最后被修改的时间 */
    localtime_r(&file_stat.st_mtim.tv_sec, &file_tm);
    strftime(time_str, sizeof(time_str),"%Y-%m-%d %H:%M:%S", &file_tm);
    printf("time of last modification: %s\n", time_str);

    /* 打印文件状态最后改变的时间 */
    localtime_r(&file_stat.st_ctim.tv_sec, &file_tm);
    strftime(time_str, sizeof(time_str),"%Y-%m-%d %H:%M:%S", &file_tm);
    printf("time of last status change: %s\n", time_str);

    exit(0);
}