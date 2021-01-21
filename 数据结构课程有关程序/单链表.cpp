//链式结构
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAXSIZE 100

//顺序表结构体定义
typedef struct  node {
	int data;  /*每个元素数据信息*/
	struct node* next;  /*存放后继元素的地址*/
} LNode, * LinkList;

//函数申明区
LinkList Creat_LinkList(void);//创建一个单链表
void Destroy_LinkList(LinkList* PL);//销毁单链表
LinkList Input_LinkList(LinkList L);//将数据输入到单链表中
int Length_LinkList(LinkList L);//获得单链表长度
LinkList Location_LinkList(LinkList L, int x);//查找，定位数据的位置
int Insert_LinkList(LinkList PL, int i, int x);//在单链表中插入
int Delete_LinkList(LinkList PL, int i);//删除第i个元素
void Output_LinkList(LinkList PL);//输出单链表

//主函数
int main(void)
{
	LinkList PL;
	PL = Creat_LinkList();
	PL = Input_LinkList(PL);
	printf("获取单链表当前的长度为:%d\n", Length_LinkList(PL));
	printf("数据10在顺序表中的位置是:%d\n", Location_LinkList(PL, 10));
	//测试程序的正确性
	Output_LinkList(PL);
	//Insert_LinkList(PL, 4, 29);
	//Insert_LinkList(PL, -1, 34);
	Insert_LinkList(PL, 7, 34);
	Insert_LinkList(PL, 13, 23);
	Output_LinkList(PL);
	Delete_LinkList(PL, 7);
	printf("删除第7个数后的结果:\n");
	
	Output_LinkList(PL);
	Delete_LinkList(PL, 13);
	printf("删除第13个数后的结果:\n");
	Output_LinkList(PL);
	Destroy_LinkList(&PL);
	return 0;

}

/*创建空单链表，入口参数：无；返回值：单链表的头指针，0代表创建失败，非0表成功*/
LinkList  Creat_LinkList(void)
{
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if (H)   /*确认创建头结点创建是否成功，若成功，修改单链表头结点的指针域为0表空表*/
		H->next = NULL;
	return H;
}

/*销毁单链表，入口参数：单链表头指针的地址，出口参数：无*/
void Destroy_LinkList(LinkList* H)
{
	LinkList p, q;
	p = *H;
	while (p != NULL)  /*释放单链表的所有结点*/
	{
		q = p;
		p = p->next;
		free(q);
	}  /*while */
	*H = NULL;   /*将头指针变为零表示单链表不存在*/
}

//数据输入
LinkList Input_LinkList(LinkList H)
{
	LinkList   p, q;
	p = H;
	int i;
	for (i = 1; i <= 10; i++)
	{
		q = (LinkList)malloc(sizeof(LNode));
		if (!q) 
		{
			printf("申请空间失败\n");
			return (0);
		}     /*申请空间失败，不能插入*/
		/*插入法1*/
		q->data = i + 3;
		q->next = p->next;
		p->next = q;
		/*插入法2*/
		//q->next = NULL;
		//p->next = q;
		//p = p->next;
	}

	return H;
}

/* 求单链表表长，入口参数：单链表头指针，出口参数：表长，-1表示单链表不存在。*/
int  Length_LinkList(LinkList  H)
{
	LinkList  p = H;   /* p指向头结点*/
	int  count = -1;  /*H带头结点所以从－1开始*/
	while (p)
	{ /* p所指的是第 count + 1 个结点*/
		p = p->next;
		count++;
	}  /*while */
	return (count);
}

//查找，定位数据位置
LinkList Location_LinkList(LinkList H, int x)
{	/*
	LinkList p;
	int j;
	p = H;
	j = 0;
	while (p && j < 1)
	{
		p = p->next;
		j++;
	}
	if (j != i || !p)
	{
		printf("参数i错或单链表不存在\n");
		return(NULL);
	}
	return p;
	*/
	LNode *p = H->next;
	while (p && p->data != x)
	{
		p = p->next;
	}
	return p;
}

//在单链表中插入
int Insert_LinkList(LinkList H, int i, int x)
{
	LinkList p, q;
	p = Location_LinkList(H, i - 1);
	if (!p)
	{
		printf("i有误\n");
		return 0;
	}
	q = (LinkList)malloc(sizeof(LNode));
	if (!q)
	{
		printf("申请空间失败\n");
		return 0;
	}
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

//删除第i个元素
int Delete_LinkList(LinkList H, int i)
{
	LinkList p, q;
	

	if (H == NULL || H->next == NULL)
	{
		printf("链表不存在或者空表不能删除\n");
		return 0;
	}
	p = Location_LinkList(H, i - 1);
	if (p == NULL || p->next == NULL)
	{
		printf("参数i错误\n");
		return 0;
	}
	
	q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}

//单链表表整体输出
void Output_LinkList(LinkList H)
{
	LinkList   p;
	p = H->next;
	while (p != NULL)
	{
		printf("%3d", p->data);
		p = p->next;
	}

	printf("\n单链表当前的长度:%d\n", Length_LinkList(H));
}

