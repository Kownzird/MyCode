#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    printf("print");
    write(STDOUT_FILENO,"write\n",6);
    printf("test");

    exit(0);

    //先打印write，再打印print
}