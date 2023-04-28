#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char str1[100] = "Linux app strcat test, ";
    char str2[] = "Hello World!";

    strncat(str1, str2, 4);
    puts(str1);

    exit(0);
}