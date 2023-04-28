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
    char sendline[100];

    printf("Shm Key: %d\n",key);

    // 创建一个共享内存区
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT|0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    printf("shmid: %d\n",shmid);

    // 获取共享内存区的地址
    if ((shmaddr = shmat(shmid, NULL, 0)) == (void*) -1) {
        perror("shmmat");
        exit(1);
    }

    // 写入数据到共享内存区
    printf("Enter some text: ");
    fgets(sendline, sizeof(sendline), stdin);
    sprintf(shmaddr, "%s", sendline);

    // 读取共享内存区中的数据
    printf("Data read from shared memory: %s", shmaddr);

    while (1){
        printf("Data read from shared memory: %s", shmaddr);
        sleep(1);
    }
    

    // 删除共享内存区
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl IPC_RMID");
        exit(1);
    }

    return 0;
}
