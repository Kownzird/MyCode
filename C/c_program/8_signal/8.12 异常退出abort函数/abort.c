#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int sig){
    printf("接收到信号: %d\n", sig);
}

int main(int argc, char *argv[]){
    struct sigaction sig = {0};

    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;
    if (-1 == sigaction(SIGABRT, &sig, NULL)) {
        perror("sigaction error");
        exit(-1);
    }

    sleep(2);
    abort(); // 调用 abort
    
    for ( ; ; )
        sleep(1);

    exit(0);
}