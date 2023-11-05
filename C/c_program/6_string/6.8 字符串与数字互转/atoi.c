#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    printf("atoi: %d\n", atoi("500"));
    printf("atol: %ld\n", atol("500"));
    printf("atoll: %lld\n", atoll("500"));
    
    exit(0);
}