#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    int ret;

    ret = unlink("./a");
    if(-1==ret){
        perror("unlink error");
        exit(-1);
    }

    exit(0);
}
