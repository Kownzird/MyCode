#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <regex.h>
#include <string.h>

int main(int argc, char *argv[]){
    regmatch_t pmatch = {0};
    regex_t reg;
    char errbuf[64];
    int ret;
    char *sptr;
    int length;
    int nmatch; //最多匹配出的结果

    if (4 != argc) {
        /**********************************
        * 执行程序时需要传入两个参数:
        * arg1: 正则表达式
        * arg2: 待测试的字符串
        * arg3: 最多匹配出多少个结果
        **********************************/
        fprintf(stderr, "usage: %s <regex> <string> <nmatch>\n", argv[0]);
        exit(0);
    }

    /* 编译正则表达式 */
    if(ret = regcomp(&reg, argv[1], REG_EXTENDED)) {
        regerror(ret, &reg, errbuf, sizeof(errbuf));
        fprintf(stderr, "regcomp error: %s\n", errbuf);
        exit(0);
    }

    /* 赋值操作 */
    sptr = argv[2]; //待测试的字符串
    length = strlen(argv[2]);//获取字符串长度
    nmatch = atoi(argv[3]); //获取最大匹配数

    /* 匹配正则表达式 */
    for (int j = 0; j < nmatch; j++) {
        char temp_str[100];
        /* 调用 regexec 匹配正则表达式 */
        if(ret = regexec(&reg, sptr, 1, &pmatch, 0)) {
            regerror(ret, &reg, errbuf, sizeof(errbuf));
            fprintf(stderr, "regexec error: %s\n", errbuf);
            goto out;
        }
        if(-1 != pmatch.rm_so) {
            if (pmatch.rm_so == pmatch.rm_eo) {//空字符串
                sptr += 1;
                length -= 1;
                printf("\n"); //打印出空字符串
                if (0 >= length)//如果已经移动到字符串末尾、则退出
                break;
                continue; //从 for 循环开始执行
            }
            memset(temp_str, 0x00, sizeof(temp_str));//清零缓冲区
            memcpy(temp_str, sptr + pmatch.rm_so,
            pmatch.rm_eo - pmatch.rm_so);//将匹配出来的子字符串拷贝到缓冲区
            printf("%s\n", temp_str); //打印字符串
            sptr += pmatch.rm_eo;
            length -= pmatch.rm_eo;
            if (0 >= length)
            break;
        }
    }
/* 释放正则表达式 */
out:
    regfree(&reg);
    exit(0);
}