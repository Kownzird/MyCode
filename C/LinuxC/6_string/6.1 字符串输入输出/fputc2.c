#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *fp = NULL;

    fp = fopen("./test_file","a");
    if(NULL==fp){
        perror("fopen error");
        exit(-1);
    }

    /* 输入字符到文件 */
    fputc('A', fp);
    fputc('B', fp);
    fputc('C', fp);
    fputc('D', fp);
    fputc(97, fp);
    fputc('\n', fp);

    fclose(fp);
    exit(0);
}