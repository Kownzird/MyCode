#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BUFF_SIZE 256

int main()
{
    int sockfd;
    char buffer[BUFF_SIZE];

    struct sockaddr_in serv_addr;
    struct hostent *server;

    // 创建 socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // 获取远程主机名和地址
    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    // 初始化 socket 地址结构
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;     // IPv4 协议族
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);   // 端口号

    // 连接服务器
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // 向服务器发送消息
    const char* message = "Hello, world!";
    int n = write(sockfd, message, strlen(message));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // 从服务器接收响应消息
    bzero(buffer, BUFF_SIZE);
    n = read(sockfd, buffer, BUFF_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Server says: %s\n", buffer);

    close(sockfd);

    return 0;
}
