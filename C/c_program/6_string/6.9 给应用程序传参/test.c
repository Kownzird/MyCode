#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i = 0;
    
    printf("Number of parameters: %d\n", argc);
    for (i = 0; i < argc; i++){
        printf(" %s\n", argv[i]);
    }
    
    exit(0);
}