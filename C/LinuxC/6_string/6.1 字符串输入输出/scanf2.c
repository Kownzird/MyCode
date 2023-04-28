#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char s1[100] = {0};
    char c;

    scanf("%s", s1);
    printf("s1: %s\n", s1);

    scanf("%c", &c);
    printf("c: %d\n", c);
    
    exit(0);
}