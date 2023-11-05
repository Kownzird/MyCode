#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char buf[50]={0};
    FILE *fp = NULL;
    int size;

    /* 打开文件 */
    fp=fopen("./test_file","r");
    if(fp==NULL){
        perror("fopen error");
        exit(-1);
    }

    printf("文件打开成功!\n");

    /* 读取数据 */
    if(20 > (size=fread(buf,1,20,fp))){
        if(ferror(fp)){ //使用 ferror 判断是否是发生错误
            perror("fread error");
            fclose(fp);
            exit(-1);
        }
        /* 如果未发生错误则意味着已经到达了文件末尾 */
    }

    printf("读取数据成功!\n");
    printf("成功读取%d 个字节数据: %s\n", size, buf);

    /* 关闭文件 */
    fclose(fp);
    exit(0);

}