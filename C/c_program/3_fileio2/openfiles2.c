#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int fd1, fd2;
    char buf[4];
    int ret;
    
    /* 创建新文件 test_file 并打开 */
    fd1 = open("./test_file",O_WRONLY|O_CREAT|O_EXCL,0777);
    if(-1==fd1){
        perror("open error");
        exit(-1);
    }

    /* 再次打开 test_file 文件 */
    fd2 = open("./test_file",O_RDONLY);
    if(-1==fd2){
        perror("open error");
        goto err1;
    }

    /* 通过 fd1 文件描述符写入 4 个字节数据 */
    buf[0]=0x11;
    buf[1]=0x22;
    buf[2]=0x33;
    buf[3]=0x44;

    ret = write(fd1,buf,4);
    if(-1==ret){
        perror("write error");
        goto err2;
    }

    /* 将读写位置偏移量移动到文件头 */
    lseek(fd2,0,SEEK_SET);

    /* 读取数据 */
    memset(buf,0x00,sizeof(buf));
    ret = read(fd2,buf,4);
    if(-1==ret){
        perror("read error");
        goto err2;
    }

    printf("%x %x %x %x\n",buf[0], buf[1], buf[2], buf[3]);
    ret = 0;
err2:
    close(fd2);

err1:
    close(fd1);
    exit(ret);
}