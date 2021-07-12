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