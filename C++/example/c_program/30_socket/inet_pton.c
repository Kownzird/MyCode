#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define IPV4_ADDR "192.168.1.222"

int main(void){
    struct in_addr addr;
    char addr_a[20];

    inet_pton(AF_INET, IPV4_ADDR, &addr);
    printf("ip addr: 0x%x\n", addr.s_addr);

    exit(0);
}