/*假设以I和O分别表示进栈和出栈操作，栈的初态和终栈均为空，进栈和出栈的操作序列可表示为仅由I和O组成的序列。 
设计一个算法判定所给的操作序列是否合法。若合法返回真；否则返回假。（假设被判定的操作序列已存入一维数组中）。*/

#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

typedef int DataType;

typedef struct node
{
	DataType data;          
    struct node * next;     
}LinkStack;

int LStackIsEmpty(LinkStack *ls)/*判别空栈*/
{
	return (ls->next?0:1);
}

LinkStack *LStackPush(LinkStack *ls,DataType x)/*入栈*/
{
   LinkStack *p;
   p=(LinkStack *)malloc(sizeof(LinkStack)); 
   p->data=x;         
   p->next=ls;       
   ls=p;             
   return ls;
}

LinkStack* LStackInit()/*初始化链栈*/ 
{
	LinkStack *h; 
    h=(LinkStack*)malloc(sizeof(LinkStack));
    h->data=1; 
    h->next=NULL;
    return h; 
}
LinkStack *LStackPop(LinkStack *ls,DataType *e)/*出栈*/
{
   LinkStack *p; 
   if(!ls)
   {
	  printf("\n链栈是空的!");
	  return NULL;
   }  
   p=ls;  
   *e=p->data; 
   ls=ls->next;        
   free(p);
   return ls;
}

int judge(char str[],int n)/*判断算法*/
{
	int i=0;
	DataType x;
	LinkStack *ls;
	int flag=1;
	ls=LStackInit();
	while(i<n&&flag)
	{
		if(str[i]=='I')
		{
			ls=LStackPush(ls,str[i]);
		}
		else if (str[i]=='O')
		{
			if(LStackIsEmpty(ls))
				flag=0;
			else
				ls=LStackPop(ls,&x);
		}
		else
		{
			flag=0;
		}
		i++;
	}
	if(!LStackIsEmpty(ls))
		flag=0;
	return flag;
}

int main()
{
	
	char str[100];
	printf("请输入操作序列,I表示入栈,O表示出栈:\n");
	scanf("%s",str);
	int n=strlen(str);
	int flag=judge(str,n);
	if(flag)
		printf("该操作合法");
	else
		printf("该操作不合法");
	return 0;
}