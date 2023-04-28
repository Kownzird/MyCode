#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char buf[50];
    int ret;

    memset(buf,0x0,sizeof(buf));
    ret = readlink("./link_soft.c",buf,sizeof(buf));
    if(-1==ret){
        perror("readlink error");
        exit(-1);
    }

    printf("buf=%s\n",buf);
    exit(0);
}