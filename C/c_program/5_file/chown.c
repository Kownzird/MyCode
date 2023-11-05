#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){

    printf("uid:%d\n",getuid());
    printf("gid:%d\n",getgid());

    if(-1==chown("./chown.c",0,0)){
        perror("chown error");
        exit(-1);
    }

    printf("uid:%d\n",getuid());
    printf("gid:%d\n",getgid());

    exit(0);
}