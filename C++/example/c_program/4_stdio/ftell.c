#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    FILE *fp = NULL;
    int size;

    /* 打开文件 */
    fp=fopen("./ftell.c","r");
    if(fp==NULL){
        perror("fopen error");
        exit(-1);
    }

    printf("文件打开成功!\n");

    /* 将读写位置移动到文件末尾 */
    if(0 > fseek(fp,0,SEEK_END)){
        perror("fseek error");
        fclose(fp);
        exit(-1);
    }

    /* 获取当前位置偏移量 */
    if(0 > (size=ftell(fp))){
        perror("ftell error");
        fclose(fp);
        exit(-1);
    }


    printf("文件的大小: %d字节\n",size);

    /* 关闭文件 */
    fclose(fp);
    exit(0);

}