#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void func(void){
    /*...... */
    printf("fun()...\n");
}
static void sig_handler(int sig){
    printf("Sig Hnadler Start\n");
    func();
    printf("Sig Hnadler End\n");
}

int main(int argc, char *argv[]){
    sig_t ret = NULL;
    ret = signal(SIGINT, (sig_t)sig_handler);
    if (SIG_ERR == ret) {
        perror("signal error");
        exit(-1);
    }
    /* 死循环 */
    for ( ; ; ){
        func();
        sleep(1);
    }
        
    exit(0);
}