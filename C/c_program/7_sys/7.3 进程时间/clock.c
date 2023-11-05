#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    clock_t t_start;
    clock_t t_end;
    int i, j;

    /* 开始时间 */
    t_start = clock();
    if (-1 == t_start){
        exit(-1);
    }
    

    /* *****需要进行测试的代码段***** */
    for (i = 0; i < 20000; i++)
        for (j = 0; j < 20000; j++)
            ;

    /* *************end************** */
    /* 结束时间 */
    t_end = clock();
    if (-1 == t_end){
        exit(-1);
    }
    
    /* 打印时间 */
    printf("总的 CPU 时间: %fs\n", (t_end - t_start) / (double)CLOCKS_PER_SEC);

    exit(0);
}