#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    char tm_str[100]={0};
    time_t tm;

    /* 获取时间 */
    tm = time(NULL);
    if(-1 == tm){
        perror("time error");
        exit(-1);
    }

    /* 将时间转换为字符串形式 */
    ctime_r(&tm, tm_str);

    /* 打印输出 */
    printf("当前时间: %s\n", tm_str);
    printf("当前时间：%s\n", ctime(&tm));
    exit(0);

}