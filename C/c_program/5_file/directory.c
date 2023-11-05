#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

int main(void){
    struct dirent *dir;
    DIR *dirp;
    int ret = 0;

    /* 打开目录 */
    dirp = opendir("./my_dir");
    if (NULL == dirp) {
        perror("opendir error");
        exit(-1);
    }

    /* 循环读取目录流中的所有目录条目 */
    errno = 0;
    while (NULL != (dir = readdir(dirp))){
        printf("%s %ld\n", dir->d_name, dir->d_ino);
    }
    
    if (0 != errno) {
        perror("readdir error");
        ret = -1;
        goto err;
    } else{
        printf("End of directory!\n");
    }
    
err:
    closedir(dirp);
    exit(ret);
}