#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    key_t key = 1234;
    int shmid;
    char *shmaddr;

    printf("Shm Key: %d\n",key);

    // 获取共享内存区的ID
    if ((shmid = shmget(key, SHM_SIZE, 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    printf("shmid: %d\n",shmid);

    // 连接到共享内存区
    if ((shmaddr = shmat(shmid, NULL, 0)) == (void*) -1) {
        perror("shmat");
        exit(1);
    }

    // 读取共享内存区中的数据并输出到控制台
    printf("Data read from shared memory: %s", shmaddr);

    // 断开与共享内存区的链接
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}
