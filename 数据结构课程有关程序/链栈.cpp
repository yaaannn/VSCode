#include<stdio.h>
#include<stdlib.h> 

typedef int DataType;

 /* 函数结果状态代码 */
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR -1
 #define INFEASIBLE -1

typedef struct node
{
	DataType data;          /*数据域*/
    struct node * next;     /*指针域*/
}LinkStack; 

LinkStack* LStackInit();
int LStackIsEmpty(LinkStack *ls);
DataType LStackGetTop(LinkStack *ls);
LinkStack *LStackPush(LinkStack *ls,DataType x);
LinkStack *LStackPop(LinkStack *ls,DataType *e);

int main(int argc,char *argv[])
{
	int a[5]={1,2,3,4,5},i,isEmtpy;
	LinkStack *linkStack;
	DataType tmp; 
	linkStack = LStackInit();/*初始化链栈*/
	printf("\n依次向链栈内压入1,2,3,4,5!\n" ); 
	for(i=1;i<5;i++)
		linkStack=LStackPush(linkStack,a[i]);
	printf("栈顶元素为:");
	printf("%d\n",LStackGetTop(linkStack));      
	linkStack=LStackPop(linkStack,&tmp);/*把栈顶元素出栈*/
	printf("出栈后的栈顶元素是:");
	printf("%d\n",LStackGetTop(linkStack));
	isEmtpy = LStackIsEmpty(linkStack);/*判断是否为空栈*/
	if(isEmtpy==0)
		printf("当前链栈为非空链栈!\n");
	else
		printf("当前链栈为空链栈!\n");
	return 0;
}

LinkStack* LStackInit()/*初始化链栈*/ 
{
	LinkStack *h; 
    h=(LinkStack*)malloc(sizeof(LinkStack));
    h->data=1; 
    h->next=NULL;
    return h; 
}

int LStackIsEmpty(LinkStack *ls)/*判别空栈*/
{
	return (ls->next?FALSE:TRUE);
}

DataType LStackGetTop(LinkStack *ls)/*取栈顶元素*/
{
   if(!ls)
   {
     printf("\n栈是空的!");
     return ERROR;
   }
  return ls->data;
}

LinkStack *LStackPush(LinkStack *ls,DataType x)/*入栈*/
{
   LinkStack *p;
   p=(LinkStack *)malloc(sizeof(LinkStack));/*分配空间*/ 
   p->data=x;         /*设置新结点的值*/
   p->next=ls;       /*将新元素插入栈中*/
   ls=p;             /*将新元素设为栈顶*/
   return ls;
}

LinkStack *LStackPop(LinkStack *ls,DataType *e)/*出栈*/
{
   LinkStack *p; 
   if(!ls)/*判断是否为空栈*/ 
   {
	  printf("\n链栈是空的!");
	  return NULL;
   }  
   p=ls;  /*指向被删除的栈顶*/
   *e=p->data;/*返回栈顶元素*/ 
   ls=ls->next; /*修改栈顶指针*/        
   free(p);
   return ls;
}

