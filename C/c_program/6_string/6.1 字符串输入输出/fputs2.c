#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp = NULL;

    /* 创建一个文件 */
    fp = fopen("./test_file", "a");
    if (NULL == fp) {
        perror("fopen error");
        exit(-1);
    }

    fputs("Hello World! 1\n", fp);
    fputs("Hello World! 2\n", fp);

    /* 关闭文件 */
    fclose(fp);
    exit(0);
}