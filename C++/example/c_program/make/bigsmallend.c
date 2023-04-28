#include<stdio.h>

/**
 * 大小端检测
*/

void pointerTest(){
    //使用指针来检测
    int a = 1;

    //大端数据低位存储在高地址
    //小端数据低位存储在低地址
    char *p = (char*)&a;

    if(*p == 1){
        printf("Small End\n");
    }else{
        printf("Big End\n");
    }
}

void unionTest(){
    union Un{
        int i;
        char a;
    }u;

    u.i=1;
    if(1==u.a){
        printf("Small End\n");
    }else{
        printf("Big End\n");
    }
}

int main(int argc, char *argv[]){
    // pointerTest();
    unionTest();
}