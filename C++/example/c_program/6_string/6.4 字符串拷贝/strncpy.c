#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char str1[100] = "AAAAAAAAAAAAAAAAAAAAAAAA";
    char str2[] = "Hello World!";

    strncpy(str1, str2, 5);
    puts(str1);
    puts("~~~~~~~~~~~~~~~");
    strncpy(str1, str2, 20);
    puts(str1);
    
    exit(0);
}