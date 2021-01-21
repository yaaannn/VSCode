#include<stdio.h>
#include<stdlib.h> 


typedef int DataType;
#define MAXNUM 100
 /* 函数结果状态代码 */
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR -1
 #define INFEASIBLE -1

typedef struct/*顺序栈定义*/ 
{ 
    DataType data[MAXNUM];    /*  存放栈的数据元素  */
    int top;              /*  栈顶指针，用来存放栈顶元素在数组中的下标  */
}SeqStack;

void SStackSetNull(SeqStack *s);
int SStackIsEmpty(SeqStack *s);
int SStackIsFull(SeqStack *s);
int SStackPush(SeqStack *s, DataType x);
int SStackPop(SeqStack *s, DataType *x);
DataType SStackGetTop(SeqStack *s);
void SStackPrint(SeqStack  *s);

int main(int argc,char *argv[])
{
    int n;
    DataType x;
    SeqStack  ss;
    int  read=0 ;
    do
    {
        puts("        关于顺序栈的操作\n");
        puts("         ======================\n");
        puts("        1 ------ 置空栈");
        puts("        2 ------ 入栈");
        puts("        3 ------ 出栈");
        puts("        4 ------ 输出");
        puts("        0 ------ 退出");
        printf("        请选择代号（0-4）");
        scanf("%d",&read);
        printf("\n");
        switch(read)
        {
            case  1:
				SStackSetNull(&ss);
                break;
            case  2:
                printf("    输入入栈元素个数:");
                scanf("%d",&n);
				printf("    输入入栈数据元素:");
                for(int i=0;i<n;i++)
                {
                scanf("%d",&x);
                SStackPush(&ss,x);
                }
                break;
            case  3:
				if (SStackPop(&ss,&x)!=FALSE)
					printf("    出栈数据元素是: %d\n",x);
                break;
            case  4:
				SStackPrint(&ss);
                break;
            case  0  : 
				read=0 ;
                break;
        }
    }while(read!=0 );
	return 0;
}

void SStackSetNull(SeqStack *s)   /*置空栈*/
{
    s->top =-1;
}

int SStackIsEmpty(SeqStack *s)    /*判断栈S为空栈时返回值为真，反之为假*/
{
    return(s->top<0?TRUE:FALSE);
}

int SStackIsFull(SeqStack *s)        /*判断栈S为满栈时返回值为真，反之为假*/
{
    return(s->top==MAXNUM-1?TRUE:FALSE);
}


int SStackPush(SeqStack *s, DataType x)
{
    if (s->top==MAXNUM-1)
    {
        printf("栈上溢出!\n");
        return FALSE;
    }
    else
    {
        s->top = s->top + 1;
        s->data[s->top]=x;
        return TRUE;
    }
}


int SStackPop(SeqStack *s, DataType *x)
{
    if (s->top==-1)
    {
        printf("栈下溢出!\n");
        return FALSE;
    }
    else
    {
        *x=s->data[s->top];
        s->top--;
        return TRUE;
    }
}

DataType SStackGetTop(SeqStack *s)
{
    if (s->top ==-1)
    {
        printf("栈下溢出!\n");
        return FALSE;
    }
    else
        return (s->data[s->top]);
}
void SStackPrint(SeqStack  *s)
{
    int p;
    if(SStackIsEmpty(s)==TRUE)
        printf("        栈空!\n\n");   
    else
    {
        printf("          栈数据元素如下:\n\n");
        p=s->top;
        while(p>=0)
        {
            printf(" %d ",s->data[p]);
            p--;
        }
        printf("\n\n");
    }
}

