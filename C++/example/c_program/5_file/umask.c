#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    mode_t old_mask;

    old_mask = umask(0003);
    printf("old mask = %04o\n",old_mask);

    old_mask = umask(0007);
    printf("old mask = %04o\n",old_mask);

    exit(0);
}