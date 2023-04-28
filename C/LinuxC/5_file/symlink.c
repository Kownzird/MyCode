#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){

    int ret;

    ret = symlink("./link.c","./link_soft.c");
    if(-1==ret){
        perror("symlink error");
        exit(-1);
    }

    exit(0);
}