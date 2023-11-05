#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
    signal(SIGHUP, SIG_IGN);
    for ( ; ; ) {
        sleep(1);
        puts("进程运行中......");
    }
}