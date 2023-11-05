#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ret;
    ret = chmod("./chmod.c", 0744);
    if (-1 == ret) {
        perror("chmod error");
        exit(-1);
    }
    
    exit(0);
}