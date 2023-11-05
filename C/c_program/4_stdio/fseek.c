#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char rd_buf[100]={0};
    char wr_buf[]="Hello world!\n";
    FILE *fp = NULL;
    int size;

    /* 打开文件 */
    fp=fopen("./test_file","w+");
    if(fp==NULL){
        perror("fopen error");
        exit(-1);
    }

    printf("文件打开成功!\n");

    /* 写文件 */
    if(sizeof(wr_buf) > fwrite(wr_buf,1,sizeof(wr_buf),fp)){
        perror("fwrite error");
        fclose(fp);
        exit(-1);
    }
    printf("数据写入成功!\n");
    
    /* 将读写位置移动到文件头部 */
    if(0 > fseek(fp, 0, SEEK_SET)){
        perror("fseek error");
        fclose(fp);
        exit(-1);
    }

    /* 读取数据 */
    if(sizeof(wr_buf) > (size=fread(rd_buf,1,sizeof(wr_buf),fp))){
        perror("fread error");
        fclose(fp);
        exit(-1);
    }

    printf("读取数据成功!\n");
    printf("成功读取%d 个字节数据: %s\n", size, rd_buf);

    /* 关闭文件 */
    fclose(fp);
    exit(0);

}