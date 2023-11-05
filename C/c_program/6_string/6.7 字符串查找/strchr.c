#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[]="Hello world";
    char *ptr = NULL;

    ptr = strchr(str,'w');
    if(NULL!=ptr){
        printf("Character: %c\n",*ptr);
        printf("Offset: %ld\n",ptr-str);
    }

    exit(0);
}