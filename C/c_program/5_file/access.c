#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MY_FILE "./access.c"

int main(void){
    int ret;

    /* 检查文件是否存在 */
    ret = access(MY_FILE,F_OK);
    if(-1==ret){
        printf("%s: file does not exist.\n", MY_FILE);
        exit(-1);
    }

    /* 检查权限 */
    ret = access(MY_FILE, R_OK);
    if (!ret){
        printf("Read permission: Yes\n");
    }else{
        printf("Read permission: NO\n");
    }
    
    ret = access(MY_FILE, W_OK);
    if (!ret){
        printf("Write permission: Yes\n");
    }else{
        printf("Write permission: NO\n");
    }

    ret = access(MY_FILE, X_OK);
    if (!ret){
        printf("Execution permission: Yes\n");
    }else{
        printf("Execution permission: NO\n");
    }
}