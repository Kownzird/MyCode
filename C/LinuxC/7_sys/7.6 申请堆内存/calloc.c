#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *base = NULL;
    int i;

    /* 校验传参 */
    if (2 > argc){
        printf("param too few\n");
        exit(-1);
    }
    
    /* 使用 calloc 申请内存 */
    base = (int *)calloc(argc - 1, sizeof(int));
    if (NULL == base) {
        printf("calloc error\n");
        exit(-1);
    }

    /* 将字符串转为 int 型数据存放在 base 指向的内存中 */
    for (i = 0; i < argc - 1; i++){
        base[i] = atoi(argv[i+1]);
    }
    
    /* 打印 base 数组中的数据 */
    printf("你输入的数据是: ");
    for (i = 0; i < argc - 1; i++){
        printf("%d ", base[i]);
    }
    
    putchar('\n');

    /* 释放内存 */
    free(base);
    exit(0);
}