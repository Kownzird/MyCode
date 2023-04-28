#include <stdio.h>
#include <stdlib.h>

int main(void){
    char str[100]={0};
    FILE *fp = NULL;

    /* 打开文件 */
    fp = fopen("./test_file", "r");
    if (NULL == fp) {
        perror("fopen error");
        exit(-1);
    }

    /* 从文件中输入字符串 */
    fgets(str, sizeof(str), fp);
    printf("%s", str);
    
    /* 关闭文件 */
    fclose(fp);
    exit(0);
}