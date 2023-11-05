#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char str[]="Strlen and sizeof Difference";
    char *ptr = str;

    printf("str sizeof: %ld\n", sizeof(str));
    printf("str strlen: %ld\n", strlen(str));
    puts("~~~~~~~~~~");
    printf("ptr sizeof: %ld\n", sizeof(ptr));
    printf("ptr strlen: %ld\n", strlen(ptr));

    exit(0);
}