#include <stdio.h>
#include <stdlib.h>

int main(void){
    int ret;

    ret = rename("./a","./b");
    if(-1==ret){
        perror("rename error");
        exit(-1);
    }

    exit(0);
}
