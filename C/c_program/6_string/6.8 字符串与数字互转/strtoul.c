#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    printf("strtoul: %lu\n", strtoul("0x500", NULL, 16));
    printf("strtoul: %lu\n", strtoul("0x500", NULL, 0));
    printf("strtoul: %lu\n", strtoul("500", NULL, 16));
    printf("strtoul: %lu\n", strtoul("0777", NULL, 8));
    printf("strtoul: %lu\n", strtoul("0777", NULL, 0));
    printf("strtoul: %lu\n", strtoul("1111", NULL, 2));
    
    exit(0);
}