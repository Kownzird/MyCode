#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int ch;
    ch = fgetc(stdin);
    printf("%c\n", ch);
    exit(0);
}