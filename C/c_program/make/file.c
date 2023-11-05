#include<stdio.h>

typedef struct{
    char *name;
    int age;
    double height;
}Person;

int main(){
    FILE *fp = fopen("test.txt","w+");
    if(fp == NULL){
        printf("Open file fail\n");
        return -1;
    }

    char *str = "123456789";
    fputs(str,fp);
    printf("ftell=%d\n",ftell(fp));

    fseek(fp,3,SEEK_SET);
    fputs("Kz",fp);
    printf("ftell=%d\n",ftell(fp));

    fclose(fp);
}