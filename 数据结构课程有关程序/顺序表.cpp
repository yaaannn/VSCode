//分别实现顺序表的6个基本运算，初始化，销毁，求表长，按值检索，插入，删除等操作，并实现main程序。

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAXSIZE 100

//顺序表结构体定义
typedef struct node {
	int data[MAXSIZE];
	int length;
}SeqList, * PSeqList;

//函数申明区
PSeqList Init_SeqList(void);//创建一个顺序表
void Destroy_SeqList(PSeqList *PL);//销毁顺序表
PSeqList Input_SeqList(PSeqList L);//将数据输入到顺序表中
int Length_SeqList(PSeqList L);//获得表长度
int Location_SeqList(PSeqList L,int x);//查找，定位数据的位置
int Insert_SeqList( PSeqList PL, int i, int x);//在顺序表中插入
int Delete_SeqList( PSeqList PL,int i);//删除第i个元素
void Output_SeqList(PSeqList PL);//输出顺序表


//主函数
int main(void)
{
	PSeqList PL; 
	PL = Init_SeqList();
	PL = Input_SeqList(PL);
	printf("获取顺序表当前的长度为:%d\n",Length_SeqList(PL));
	printf("数据10在顺序表中的位置是:%d\n",Location_SeqList(PL,10));
	//测试程序的正确性
	Output_SeqList(PL);
	Insert_SeqList(PL,4,29);
	Insert_SeqList(PL,-1,34);
	Insert_SeqList(PL,7,34);
	Insert_SeqList(PL,13,23); 
	Output_SeqList(PL);
	Delete_SeqList(PL,3);
	printf("删除第3个数后的结果:\n");
	Output_SeqList(PL);
	Delete_SeqList(PL,4);
	printf("删除第4个数后的结果:\n");
	Output_SeqList(PL);
	Destroy_SeqList(&PL);
	return 0;


}


//创建一个顺序表，入口参数无，返回一个指向顺序表的指针，指针值为零表示分配空间失败
PSeqList Init_SeqList(void)
{
	PSeqList PL;
	PL = (PSeqList)malloc(sizeof(SeqList));
	if(PL)
		PL->length = 0;
	else
	{
		printf("内存分配失败\n");
		exit(-1);
	}
	return (PL);
}

//销毁顺序表，入口参数：为要销毁的顺序表指针地址，无返回值
void Destroy_SeqList(PSeqList *PL)
{  
    if (*PL)
        free (*PL) ;
    *PL=NULL; 
    printf("顺序表已销毁\n");
    return ;
} 


//数据输入
PSeqList Input_SeqList(PSeqList L)
{
	int i;
	for( i = 1; i < 10; i++)
		L->data[i-1] = i+3;
	L->length = i-1;
	return L;
}

//读取顺序表的当前长度
int Length_SeqList(PSeqList L)
{
	if(!L)
	{
		printf("无PL指针，退出程序\n");
		exit(-1);
	}
	return (L->length);
}

//在顺序表上检索，入口参数为顺序表，检索元素，返回元素位置，0表示查找失败
int Location_SeqList(PSeqList L,int x)
{
	int i=0;
	while(i < L->length  &&  L->data[i] != x)
		i++;
	if(i >= L->length)
		return 0;
	else 
		return (i+1);
}

/*在顺序表的第i个元素之前插入x，入口参数为顺序表指针，插入位置，插入元素，
返回标志，1表示成功，0标志插入位置不合法，-1表示溢出，-2表示不存在*/
int Insert_SeqList(PSeqList PL, int i, int x)
{
	int j;
	if(!PL)
	{
		printf("表不存在");
		return -2;
	}
	if(PL->length>=MAXSIZE)
	{
		printf("表溢出");
		return -1;
	}
	if(i<1||i>PL->length+1)
	{
		printf("插入位置不合法");
		return 0;
	}
	for (j=PL->length-1;j>i-1;j--)
		PL->data[j+1]=PL->data[j];
	PL->data[i-1]=x;
	PL->length++;
	return 1;
} 

//删除顺序表第i个元素，入口参数：顺序表指针，删除元素位置，返回标志1表示成功，0表示删除位置不合法，-1表示表不存在
int Delete_SeqList( PSeqList PL,int i)
{
	int j;
	if(!PL)
	{
		printf("表不存在");
		return -1;
	}
	if(i<1||i>PL->length)
	{
		printf("删除位置不合法");
		return 0;
	}
	for(j=i;j<PL->length;j++)
		PL->length--;
	return 1;
}

//顺序表整体输出
void Output_SeqList(PSeqList PL)
{
	int i;
	for( i = 0; i < PL->length; i++)
		printf("%3d" , PL->data[i]);
	printf("\n顺序表当前的长度:%d\n",Length_SeqList(PL));	
}
