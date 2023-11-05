#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    int semid, pid;
    struct sembuf p = {0, -1, SEM_UNDO};  // P 操作结构体
    struct sembuf v = {0, 1, SEM_UNDO};   // V 操作结构体

    // 创建信号量集，其中包含一个信号量
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | IPC_EXCL | 0666);
    if(semid < 0) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    // 初始化信号量值为 1
    if(semctl(semid, 0, SETVAL, 1) < 0) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    // 父进程和子进程交替执行两个临界区
    if((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if(pid == 0) {  // 子进程
        while(1) {
            sleep(rand() % 3);    // 模拟随机性

            printf("[pid:%d] tries to enter the critical section\n", getpid());

            if(semop(semid, &p, 1) == -1) {  // 进入临界区前先 P 操作
                perror("semop");
                exit(EXIT_FAILURE);
            }

            printf("[pid:%d] enters the critical section\n", getpid());
            fflush(stdout);

            sleep(2);   // 持有临界区 2 秒钟

            printf("[pid:%d] leaves the critical section\n", getpid());

            if(semop(semid, &v, 1) == -1) {  // 离开临界区后先 V 操作
                perror("semop");
                exit(EXIT_FAILURE);
            }
        }
    } else {    // 父进程
        while(1) {
            sleep(rand() % 3);    // 模拟随机性

            printf("[pid:%d] tries to enter the critical section\n", getpid());

            if(semop(semid, &p, 1) == -1) {  // 进入临界区前先 P 操作
                perror("semop");
                exit(EXIT_FAILURE);
            }

            printf("[pid:%d] enters the critical section\n", getpid());
            fflush(stdout);

            sleep(2);   // 持有临界区 2 秒钟

            printf("[pid:%d] leaves the critical section\n", getpid());

            if(semop(semid, &v, 1) == -1) {  // 离开临界区后先 V 操作
                perror("semop");
                exit(EXIT_FAILURE);
            }
        }
    }

    // 删除信号量集
    if(semctl(semid, 0, IPC_RMID, NULL) < 0) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}
