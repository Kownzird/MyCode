#include<stdio.h>
 
int main()
{
    int f1=1,f2=1,f;
    int i,n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("%d ",f1);

        f=f1+f2;
        f1=f2;
        f2=f;
    }
    
    return 0;
}