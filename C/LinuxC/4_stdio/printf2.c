#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
    /**
     * 将标准输出改为无缓冲模式
    */
    if(setvbuf(stdout,NULL,_IONBF,0)){
        perror("setvbuf error");
        exit(-1);
    }

    printf("Hello world\n");
    printf("Hello world");

    for(;;){
        sleep(1);
    }
}