#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *ptr = NULL;
    char str[] = "I love my home";

    ptr = strchr(str, 'o');
    if (NULL != ptr){
        printf("strchr: %ld\n", ptr - str);  //3
    }
    
    ptr = strrchr(str, 'o');
    if (NULL != ptr){
        printf("strrchr: %ld\n", ptr - str); //11
    }
    
    exit(0);
}