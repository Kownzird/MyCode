#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void sig_handler(int signo) {
    printf("Received SIGUSR1 signal.\n");
}

int main() {
    printf("开始计时\n");
    time_t start_time = time(NULL);

    signal(SIGINT, sig_handler);
    sigset_t block_set;
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGINT);
    sigprocmask(SIG_BLOCK, &block_set, NULL);

    sigset_t pending_set;
    sigemptyset(&pending_set);
    while (sigismember(&pending_set, SIGINT) == 0) {
        sleep(1);
        if (sigpending(&pending_set) != 0) {
            printf("Error in sigpending() function.\n");
            return -1;
        }
    }

    time_t end_time = time(NULL);
    printf("经过了%ld秒\n", end_time - start_time);

    return 0;
}
