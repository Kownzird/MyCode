#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char buf[20]={0};
    FILE *fp = NULL;
    int size;

    /* 打开文件 */
    fp=fopen("./test_file","r");
    if(fp==NULL){
        perror("fopen error");
        exit(-1);
    }

    /* 将读写位置移动到文件末尾 */
    if(0 > fseek(fp,0,SEEK_END)){
        perror("fseek error");
        fclose(fp);
        exit(-1);
    }
    
    /* 读文件 */
    if(10 > fread(buf,1,10,fp)){
        if(feof(fp)){
            printf("end-of-file 标志被设置,已到文件末尾!\n");
        }
        clearerr(fp); //清楚标志
    }

    /* 关闭文件 */
    fclose(fp);
    exit(0);

}