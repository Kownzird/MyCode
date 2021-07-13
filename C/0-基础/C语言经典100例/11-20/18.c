// 题目：求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。

// 程序分析：关键是计算出每一项的值。

#include<stdio.h>

int main()
{
    int a,n,t;
    int s=0;
    scanf("%d %d",&a,&n);
    printf("a=%d n=%d\n",a,n);
    t=a;
    while (n>0)
    {
        s+=t;
        t*=10;
        t+=a;
        printf("t=%d\n",t);
        n--;
    }
    printf("%d\n",s);
    
}