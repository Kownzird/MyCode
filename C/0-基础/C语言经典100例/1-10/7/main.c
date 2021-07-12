#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    int i,j;
    SetConsoleOutputCP(437);
    char a=176,b=219;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(i==j||(i+j+1)==5)
                printf("%c",b);
            else
                printf("%c%c",a,a);
        }
        printf("\n");
    }
}