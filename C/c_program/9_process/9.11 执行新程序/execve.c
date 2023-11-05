#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *arg_arr[5];
    char *env_arr[5] = {"NAME=app", "AGE=25", "SEX=man", NULL};
    if (2 > argc){
        exit(-1);
    }
    
    arg_arr[0] = argv[1];
    arg_arr[1] = "Hello";
    arg_arr[2] = "World";
    arg_arr[3] = NULL;

    execve(argv[1], arg_arr, env_arr);
    
    perror("execve error");
    exit(-1);
}