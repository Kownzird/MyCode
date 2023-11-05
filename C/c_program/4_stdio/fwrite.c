#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char buf[]="Hello world!\n";
    FILE *fp = NULL;

    /* 打开文件 */
    fp=fopen("./test_file","w");
    if(fp==NULL){
        perror("fopen error");
        exit(-1);
    }

    printf("文件打开成功!\n");

    /* 写入数据 */
    if(sizeof(buf) > fwrite(buf,1,sizeof(buf),fp)){
        perror("fwrite error");
        fclose(fp);
        exit(-1);
    }

    printf("写入数据成功!\n");

    /* 关闭文件 */
    fclose(fp);
    exit(0);

}