#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    printf("SIGINT 描述信息: %s\n", strsignal(SIGINT));
    printf("SIGQUIT 描述信息: %s\n", strsignal(SIGQUIT));
    printf("SIGBUS 描述信息: %s\n", strsignal(SIGBUS));
    printf("编号为 1000 的描述信息: %s\n", strsignal(1000));
    exit(0);
}