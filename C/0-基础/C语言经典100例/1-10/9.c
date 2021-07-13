// 题目：要求输出国际象棋棋盘。

// 程序分析：国际象棋棋盘由64个黑白相间的格子组成，分为8行*8列。用i控制行，j来控制列，根据i+j的和的变化来控制输出黑方格，还是白方格。

#include<stdio.h>
#include<windows.h>

int main()
{
    int i,j;
    char w=219,b=176;
    SetConsoleOutputCP(437);
    for(i=1; i<9; i++)
    {
        for(j=1; j<9; j++)
        {
            if((i+j)%2==0)
            {
                printf("%c%c",w,w);
            }
            else
            {
                printf("%c%c",b,b);
            }
        }
        printf("\n");
    }
}