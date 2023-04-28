#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void){
    char buf[100];
    char *ptr;

    memset(buf,0x0,sizeof(buf));

    ptr = getcwd(buf,sizeof(buf));
    if(NULL == ptr){
        perror("getcwd error");
        exit(-1);
    }

    ptr = getcwd(NULL,0);
    if(NULL!=ptr){
        printf("Current working directory: %s\n",ptr);
        free(ptr);
    }
    
    printf("Current working directory: %s\n", buf);
    exit(0);
}