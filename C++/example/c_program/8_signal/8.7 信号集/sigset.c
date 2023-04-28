#include <stdio.h>
#include <signal.h>

// 调用 sigemptyset() 函数初始化空信号集，并打印出来；
// 调用 sigfillset() 函数初始化全信号集，并打印出来；
// 调用 sigaddset() 函数向空信号集中添加 SIGINT 和 SIGQUIT 信号，并打印出来；
// 调用 sigdelset() 函数从信号集中删除 SIGQUIT 信号，并打印出来；
// 调用 sigismember() 函数判断某个信号是否在信号集中，并在上面的步骤中使用了。

void printSigset(sigset_t set) {
    for (int i = 1; i <= 64; ++i) {  // 打印信号集中所有信号的状态
        if (sigismember(&set, i)) {
            putchar('1');
        } else {
            putchar('0');
        }
    }
    printf("\n");
}

int main() {
    sigset_t set;

    // 初始化空信号集
    sigemptyset(&set);
    printf("Empty set: ");
    printSigset(set);

    // 初始化全信号集
    sigfillset(&set);
    printf("Full set: ");
    printSigset(set);

    // 向信号集中添加 SIGINT 和 SIGQUIT 信号
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);
    printf("Added set: ");
    printSigset(set);

    // 从信号集中删除 SIGQUIT 信号
    sigdelset(&set, SIGQUIT);
    printf("Deleted set: ");
    printSigset(set);

    return 0;
}
