#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFF_SIZE 256

int main()
{
    int sockfd, newsockfd, clilen;
    char buffer[BUFF_SIZE];

    struct sockaddr_in serv_addr, cli_addr;

    // 创建 socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // 初始化 socket 地址结构
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;     // IPv4 协议族
    serv_addr.sin_addr.s_addr = INADDR_ANY;   // 任意本地地址
    serv_addr.sin_port = htons(PORT);   // 端口号

    // 将套接字绑定到指定端口
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // 监听连接请求
    listen(sockfd, 5);

    // 接受客户端连接请求，并创建新的套接字
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    // 从客户端接收数据
    bzero(buffer, BUFF_SIZE);
    int n = read(newsockfd, buffer, BUFF_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Here is the message: %s\n", buffer);

    // 向客户端发送响应消息
    const char* response = "I got your message!";
    n = write(newsockfd, response, strlen(response));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}
