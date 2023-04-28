#include <stdio.h>
#include <stdlib.h>

int main(void){
    int ch;
    FILE *fp = NULL;
    
    /* 打开文件 */
    fp = fopen("./test_file", "r");
    if (NULL == fp) {
        perror("fopen error");
        exit(-1);
    }

    /* 从文件中输入一个字符 */
    ch = fgetc(fp);
    printf("%c\n", ch);

    /* 关闭文件 */
    fclose(fp);
    exit(0);
}