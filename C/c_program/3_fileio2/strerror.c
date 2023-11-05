#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd = open("./src_file",O_RDONLY);
    if(-1==fd){
        printf("Error:%s\n",strerror(errno));
        return -1;
    }

    close(fd);
    return 0;
}