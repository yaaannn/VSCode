#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
#define MAXSIZE 100
typedef struct 
{
    DataType data[MAXSIZE];
    int top;
}SeqStack,*PSeqStack;

/*函数定义区*/
PSeqStack Init_SeqStack(SeqStack *s);
int Empty_SeqStack(SeqStack *s);
int Push_SeqStack(SeqStack *s,DataType *x);
int Pop_SeqStack(SeqStack *s,DataType *x);
void Destory_SeqStack(SeqStack *s);

/*初始化空栈*/
PSeqStack Init_SeqStack()
{
    PSeqStack S;
    S=(PSeqStack)malloc(sizeof(SeqStack));
    if(S)
        S->top=-1;
    return S;
}

/*判栈空*/
int Empty_SeqStack(PSeqStack S)
{
    if(S->top==-1)
        return 1;
    else
    {
        return 0;
    }  
}

/*出栈*/
int Pop_SeqStack(SeqStack *S,DataType *x)
{
    if(Empty_SeqStack(S))
        return 0;
    else
    {
        *x=S->data[S->top];
        S->top--;
        return 1;
    } 
}

/*入栈*/
int Push_SeqStack(PSeqStack S,DataType x)
{
    if(S->top==MAXSIZE-1)
        return 0;
    else
    {
        S->top++;
        S->data[S->top]=x;
        return 1;
    }
    
}

/*销毁栈*/
void Destory_SeqStack(PSeqStack *S)
{
    if(*S)
        free(*S);
    *S = NULL;
    return;
}

/*进制转换算法*/
int conversion(int N,int r)
{ 
    PSeqStack  S; DataType   x; /*定义一个顺序栈*/
    if(!r) 
    {   
        printf("基数不能为0");    
        return(0); 
    }    
    S=Init_SeqStack(); /*初始化栈*/
    if(!S)   
    {	
        printf("栈初始化失败");   
        return(0);  
    }
    while ( N ) {
        Push_SeqStack(S,N%r); /*余数入栈 */
        N=N/r; 
    } /* 商作为被除数继续 */    
    printf ("转换后的进制数为:"); 
    while(!Empty_SeqStack(S)) 
    { /*直到栈空退出循环 */
        Pop_SeqStack(S,&x);/*弹出栈顶元素 */
        printf ("%d",x); 
    } /*输出栈顶元素 */   
    Destory_SeqStack(&S);
}

/*主程序*/
int main()
{
    int N,r;
    printf("请输入需要转换的十进制数:");
    scanf("%d",&N);
    printf("请输入转换后的进制数:");
    scanf("%d",&r);
    conversion(N,r);
    return 0;
}
