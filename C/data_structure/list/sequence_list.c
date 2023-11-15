#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

#define SL_DATA_TYPE int

typedef SL_DATA_TYPE datatype;

typedef struct sequence_list
{
    datatype* data;
    int last;
    int size;
}sqlist;

sqlist* init_sl(int size)
{
    sqlist* sl=calloc(1,sizeof(sqlist));
    if(sl!=NULL)
    {
        sl->data=calloc(size,sizeof(datatype));
        if(sl->data==NULL)
        {
            free(sl);
            return NULL;
        }
        
        sl->last=-1;
        sl->size=size;
        printf("初始化成功\n");
        
        return sl;
    }
    else
    {
        return NULL;
    }
}



void free_sl(sqlist* sl)
{
    if(sl!=NULL)
    {
        if(sl->data!=NULL)
        {
            free(sl->data);
        }
        else
        {
            perror("data成员无申请内存空间");
        }

        free(sl);
    }
    else
    {
        perror("序列表为空");
    }
    
}

bool is_full(sqlist* sl)
{
    if(sl->last==sl->size-1)
        return true;
    else
        return false;
}

bool is_empty(sqlist* sl)
{
    if(sl->last==-1)
        return true;
    else
        return false;
}

void showlist(sqlist* sl)
{
    int pos;
    for(pos=0;pos<=sl->last;pos++)
    {
        printf("%d\t",sl->data[pos]);
    }
    printf("\n");
}

void input_node(sqlist* sl,int num)
{
    int pos;
    int i;

    if(is_full(sl))
    {
        printf("顺序表已满\n");
        return;
    }

    for(pos=0;pos<=sl->last;pos++)
    {
        if(num<sl->data[pos])
            break;
    }

    for(i=sl->last;i>=pos;i--)
    {
        sl->data[i+1]=sl->data[i];
    }
    
    sl->data[pos]=num;
    sl->last++;
        
}

void del_node(sqlist* sl,int num)
{
    int pos;
    int i;

    if(is_empty(sl))
    {
        printf("顺序表为空\n");
        return;
    }
    for(pos=0;pos<=sl->last;pos++)
    {
        if(num==sl->data[pos])
            break;
    }

    for(i=pos;i<=sl->last;i++)
    {
        sl->data[i]=sl->data[i+1];
    }

    sl->last--;
    
}


int main(int argc ,char** argv)
{
    int n;
    printf("请输入想要初始化的大小：");
    scanf("%d",&n);

    //初始化
    sqlist* sl=init_sl(n);

    while(1)
    {
        printf("请插入数值（0退出程序）\n");
        scanf("%d",&n);

        if(n>0)
        {
            //插入数据
            input_node(sl,n);
            showlist(sl);
        }

        if(n<0)
        {
            //删除数据
            del_node(sl,-n);
            showlist(sl);
        }

        if(n==0)
        {
            break;
        }
    }

    //释放
    free_sl(sl);
}