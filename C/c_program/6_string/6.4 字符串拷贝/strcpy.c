#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char str1[100]={0};
    char str2[]="Hello world";

    strcpy(str1,str2);
    puts(str1);

    exit(0);
}