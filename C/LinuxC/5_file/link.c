#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){

    int ret;

    ret = link("./link.c","./link_hard.c");
    if(-1==ret){
        perror("link error");
        exit(-1);
    }

    exit(0);
}