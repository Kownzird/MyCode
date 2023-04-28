#include <stdio.h>
#include <stdlib.h>

extern char **environ;
int main(int argc, char *argv[])
{
    char **ep = NULL;
    int j;

    for (j = 0; j < argc; j++){
        printf("argv[%d]: %s\n", j, argv[j]);
    }
    
    puts("env:");
    for (ep = environ; *ep != NULL; ep++){
        printf(" %s\n", *ep);
    }
    
    exit(0);
}