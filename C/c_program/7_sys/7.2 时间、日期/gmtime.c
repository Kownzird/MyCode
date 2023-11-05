#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    struct tm local_t;
    struct tm utc_t;
    time_t sec;

    /* 获取时间 */
    sec = time(NULL);
    if (-1 == sec) {
        perror("time error");
        exit(-1);
    }

    /* 转换得到本地时间 */
    localtime_r(&sec, &local_t);

    /* 转换得到国际标准时间 */
    gmtime_r(&sec, &utc_t);

    /* 打印输出 */
    printf("本地时间: %d 年%d 月%d 日 %d:%d:%d\n",
    local_t.tm_year + 1900, local_t.tm_mon, local_t.tm_mday,
    local_t.tm_hour, local_t.tm_min, local_t.tm_sec);

    printf("UTC 时间: %d 年%d 月%d 日 %d:%d:%d\n",
    utc_t.tm_year + 1900, utc_t.tm_mon, utc_t.tm_mday,
    utc_t.tm_hour, utc_t.tm_min, utc_t.tm_sec);
    
    exit(0);
}