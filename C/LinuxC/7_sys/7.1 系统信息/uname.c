#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    struct utsname os_info;
    int ret;

    /* 获取信息 */
    ret = uname(&os_info);
    if(-1==ret){
        perror("uname error");
        exit(-1);
    }

    /* 打印信息 */
    printf("操作系统名称: %s\n", os_info.sysname);
    printf("主机名: %s\n", os_info.nodename);
    printf("内核版本: %s\n", os_info.release);
    printf("发行版本: %s\n", os_info.version);
    printf("硬件架构: %s\n", os_info.machine);

    exit(0);
}