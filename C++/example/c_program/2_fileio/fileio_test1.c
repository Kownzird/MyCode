#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char buffer[1024];
    int fd1, fd2;
    int ret;

    /* 打开 src_file 文件 */
    fd1 = open("./src_file", O_RDONLY);
    if (-1 == fd1) {
        printf("Error: open src_file failed!\n");
        return -1;
    }

    /* 新建 dest_file 文件并打开 */
    fd2 = open("./dest_file", O_WRONLY | O_CREAT | O_EXCL, S_IRWXU | S_IRGRP | S_IROTH);
    if (-1 == fd2) {
        printf("Error: open dest_file failed!\n");
        ret = -1;
        goto err1;
    }

    /* 将 src_file 文件读写位置移动到偏移文件头 500 个字节处 */
    ret = lseek(fd1, 500, SEEK_SET);
    if (-1 == ret){
        goto err2;
    }
        
    /* 读取 src_file 文件数据，大小 1KByte */
    ret = read(fd1, buffer, sizeof(buffer));
    if (-1 == ret) {
        printf("Error: read src_file filed!\n");
        goto err2;
    }

    /* 将 dest_file 文件读写位置移动到文件头 */
    ret = lseek(fd2, 0, SEEK_SET);
    if (-1 == ret){
        goto err2;
    }
    
    /* 将 buffer 中的数据写入 dest_file 文件，大小 1KByte */
    ret = write(fd2, buffer, sizeof(buffer));
    if (-1 == ret){
        printf("Error: write dest_file failed!\n");
        goto err2;
    }
    printf("OK: test successful\n");

    ret = 0;
err2:
    close(fd2);

err1:
    close(fd1);
    return ret;
}