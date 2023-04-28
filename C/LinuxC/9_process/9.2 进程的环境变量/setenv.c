#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (3 > argc) {
        fprintf(stderr, "Error: 传入 name value\n");
        exit(-1);
    }

    /* 添加环境变量 */
    if (setenv(argv[1], argv[2], 0)) {
        perror("setenv error");
        exit(-1);
    }
    
    exit(0);
}