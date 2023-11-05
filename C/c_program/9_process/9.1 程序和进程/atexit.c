#include <stdio.h>
#include <stdlib.h>

static void bye(void){
    puts("Goodbye!");
}

int main(int argc, char *argv[]){
    if (atexit(bye)) {
        fprintf(stderr, "cannot set exit function\n");
        exit(-1);
    }
    exit(0);
}