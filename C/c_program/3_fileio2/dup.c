#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int fd1, fd2;
    unsigned char buf1[4],buf2[4];
    int ret;
    
    /* 创建新文件 test_file 并打开 */
    fd1 = open("./test_file",O_RDWR|O_CREAT|O_EXCL,0777);
    if(-1==fd1){
        perror("open error");
        exit(-1);
    }

    /* 复制文件描述符 */
    fd2 = dup(fd1);
    if(-1==fd2){
        perror("dup error");
        goto err1;
    }

    printf("fd1=%d fd2=%d\n",fd1,fd2);

    /* buffer数据初始化 */
    buf1[0]=0x11;
    buf1[1]=0x22;
    buf1[2]=0x33;
    buf1[3]=0x44;

    buf2[0]=0xaa;
    buf2[1]=0xbb;
    buf2[2]=0xcc;
    buf2[3]=0xdd;

    /* 循环写入数据 */
    for(int i=0; i<4; i++){
        ret = write(fd1, buf1, sizeof(buf1));
        if(-1==ret){
            perror("write error");
            goto err2;
        }

        ret = write(fd2, buf2, sizeof(buf2));
        if(-1==ret){
            perror("write error");
            goto err2;
        }
    }

    /* 将读写位置偏移量移动到文件头 */
    ret = lseek(fd1, 0, SEEK_SET);
    if(-1==ret){
        perror("lseek error");
        goto err2;
    }
    

    /* 读取数据 */
    for(int i=0; i<8; i++){
        ret = read(fd1, buf1, sizeof(buf1));
        if(-1==ret){
            perror("read error");
            goto err2;
        }

        printf("%x%x%x%x ",buf1[0], buf1[1], buf1[2], buf1[3]);
    }
    printf("\n");

    ret = 0;
err2:
    close(fd2);

err1:
    close(fd1);
    exit(ret);
}