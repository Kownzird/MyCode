#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void sig_handler(int sig){
    printf("Receive signal:%d\n",sig);
}

int main(){
    sig_t ret = NULL;
    
    sleep(3);

    ret = signal(SIGINT,(sig_t)sig_handler);
    if(SIG_ERR == ret){
        perror("signal error");
        exit(-1);
    }

    for(;;){
        ;
    }

    exit(0);
}