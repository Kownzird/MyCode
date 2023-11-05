#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[20]={0};

    sprintf(str,"%d",500);
    puts(str);

    memset(str, 0x0, sizeof(str));
    sprintf(str, "%f", 500.111);
    puts(str);

    memset(str, 0x0, sizeof(str));
    sprintf(str, "%u", 500);
    puts(str);

    memset(str, 0x0, sizeof(str));
    snprintf(str,sizeof(str),"The num is %ld\n",sizeof(str));
    puts(str);
    exit(0);    
}