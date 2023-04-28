#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(void){
    struct in_addr addr;
    char buf[20] = {0};
    addr.s_addr = 0xde01a8c0;

    inet_ntop(AF_INET, &addr, buf, sizeof(buf));
    printf("ip addr: %s\n", buf);
    
    exit(0);
}