#include <stdio.h>
#include <stdlib.h>

int main(void){
    char str[100]={0};

    printf("请输入字符串:");
    fgets(str,sizeof(str),stdin);
    printf("str=%s\n",str);
    
    exit(0);
}