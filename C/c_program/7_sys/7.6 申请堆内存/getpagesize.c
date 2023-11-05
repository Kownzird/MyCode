#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    printf("getpagesize=%dB\n",getpagesize());
    exit(0);
}