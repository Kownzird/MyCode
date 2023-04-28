#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // printf("Hello World!\n");
    printf("Hello World!");
    fflush(stdout);
    switch (fork()) {
        case -1:
            perror("fork error");
            exit(-1);
            case 0:
            /* 子进程 */
            exit(0);
            // _exit(0);
        default:
            /* 父进程 */
            exit(0);
    }
}