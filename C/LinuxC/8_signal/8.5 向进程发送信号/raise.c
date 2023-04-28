#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void sig_handler(int sig){
    printf("Receive signal: %d\n",sig);
}

int main(int argc, char **argv){
    struct sigaction sig = {0};
    int ret = 0;

    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;

    ret=sigaction(SIGINT, &sig, NULL);
    if(-1==ret){
        perror("sigaction error");
        exit(-1);
    }

    for(;;){
        if(0!=raise(SIGINT)){
            perror("raose error");
            exit(-1);
        }

        sleep(3);
    }

    exit(0);
}