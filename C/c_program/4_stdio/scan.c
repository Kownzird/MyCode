#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
    int a;
    float b;
    char str[100];

    printf("请输入一个整数:\n");
    scanf("%d", &a);
    printf("你输入的整数为: %d\n", a);

    printf("请输入一个浮点数:\n");
    scanf("%f", &b);
    printf("你输入的浮点数为: %f\n", b);

    printf("请输入一个字符串:\n");
    // scanf("%s", str);

    getchar();
    fgets(str,100,stdin); //允许字符串有空格产生
    printf("你输入的字符串为: %s\n", str);

    exit(0);
}