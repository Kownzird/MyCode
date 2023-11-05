#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t t;
    t = time(NULL);
    if (-1 == t) {
        perror("time error");
        exit(-1);
    }
    printf("时间值: %ld\n", t);
    exit(0);
}