#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd = open("./src_file",O_RDONLY);
    if(-1==fd){
        perror("open error");
        return -1;
    }

    close(fd);
    return 0;
}