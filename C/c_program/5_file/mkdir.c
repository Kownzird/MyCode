#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void){
    int ret;
    ret = mkdir("./new_dir", S_IRWXU |S_IRGRP | S_IXGRP |S_IROTH | S_IXOTH);

    if (-1 == ret) {
        perror("mkdir error");
        exit(-1);
    }
    
    exit(0);
}