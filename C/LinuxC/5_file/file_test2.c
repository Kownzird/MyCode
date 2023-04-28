#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// 获取文件的类型， 判断此文件对于其它用户（Other） 是否具有可读可写权限
int main(void){
    struct stat file_stat;
    int ret;

    ret = stat("./file_test1.c", &file_stat);
    if(-1==ret){
        perror("stat error");
        exit(-1);
    }

    /* 判读文件类型 */
    switch (file_stat.st_mode & S_IFMT) {
        case S_IFSOCK: 
            printf("socket"); 
            break;
        case S_IFLNK: 
            printf("symbolic link"); 
            break;
        case S_IFREG: 
            printf("regular file"); 
            break;
        case S_IFBLK: 
            printf("block device"); 
            break;
        case S_IFDIR: 
            printf("directory"); 
            break;
        case S_IFCHR: 
            printf("character device"); 
            break;
        case S_IFIFO: 
            printf("FIFO"); 
            break;
    }

    printf("\n");
    
    /* 判断该文件对其它用户是否具有读权限 */
    if (file_stat.st_mode & S_IROTH)
        printf("Read: Yes\n");
    else
        printf("Read: No\n");

    /* 判断该文件对其它用户是否具有写权限 */
    if (file_stat.st_mode & S_IWOTH)
        printf("Write: Yes\n");
    else
        printf("Write: No\n");

    exit(0);
}