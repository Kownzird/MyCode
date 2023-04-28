#include<stdio.h>

void encode(char *src, char *dst, int mode){
    FILE *fr = fopen(src,"r+");
    if(fr==NULL){
        printf("Open file %s fail\n",src);
        return;
    }

    FILE *fw = fopen(dst, "w+");
    if(fw==NULL){
        printf("Open file %s fail\n",dst);
        fclose(fr);
        return;
    }

    char ch = EOF;
    while((ch=fgetc(fr)) && (!feof(fr))){
        ch = ch ^ mode;
        fputc(ch, fw);
    }

    fclose(fr);
    fclose(fw);
}


void decode(char *src, char *dst, int mode){
    FILE *fr = fopen(src,"r+");
    if(fr==NULL){
        printf("Open file %s fail\n",src);
        return;
    }

    FILE *fw = fopen(dst, "w+");
    if(fw==NULL){
        printf("Open file %s fail\n",dst);
        fclose(fr);
        return;
    }

    char ch = EOF;
    while((ch=fgetc(fr)) && (!feof(fr))){
        ch = ch ^ mode;
        fputc(ch,fw);
    }

    fclose(fr);
    fclose(fw);
}

int main(int argc, char *argv[]){
    // encode("ascii.txt","ascii_encode.txt",666);
    encode("ascii_encode.txt","ascii.txt",666);
}