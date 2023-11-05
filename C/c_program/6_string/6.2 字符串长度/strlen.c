#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[] = "Linux app strlen test!";
    printf("String: \"%s\"\n", str);
    printf("Length: %ld\n", strlen(str));
    
    exit(0);
}