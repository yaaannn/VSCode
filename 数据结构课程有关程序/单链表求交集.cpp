#include <stdio.h>
#include<stdlib.h> 
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

//初始化链表
int InitList(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	return 1;
}
 
//输出单链表
void TraveList(LinkList L)
{
	LNode *p;
	p = L->next;
 
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//尾插法创建单链表
void CreateList(LinkList &L, int n)
{
	L = new LNode;
	L->next = NULL;
	LNode *r;
	r = L;
	for (int i = 0; i < n; i++)
	{
		printf("请输入集合第%d个元素的值:", i + 1);
		LNode *s;
		s = new LNode;
		scanf("%d", &s->data);
		s->next = NULL;
		r->next = s;
		r = s;
	}
}
 
// 链表交集
LinkList AjiaoB(LinkList &A,LinkList &B)
{   
	LinkList q,pa,pb,pre;
	pa=A->next;
	pb=B->next;
	pre=A;
     /*pre指向pa的前驱*/
	while (pa && pb)
	{
		if (pa->data < pb->data) /*若小于，删除*/
		{	
			q=pa;
			pa=pa->next;  
			pre->next=pa;
			free(q);
		}
		else if (pa->data>pb->data)/*若大于，则pb指针后移*/
			pb=pb->next;
		else  /*相等，保留，pa,pb指针后移*/
		{
			pre=pa;
			pa=pa->next;
			pb=pb->next;
		}
	}
	while(pa)   /*若单链表A没有遍历完，则将剩余的结点删除*/
	{   
		q=pa;
		pa=pa->next;
		free(q);
	}
	pre->next=NULL;
    return(A);
}

int main()
{
	LinkList A, B;
	printf("请输入集合A的长度:");
	int n1;
	scanf("%d", &n1);
	CreateList(A, n1);
	printf("集合A的元素为:");
	TraveList(A);
	printf("请输入集合B的长度:");
	int n2;
	scanf("%d", &n2);
	CreateList(B, n2);
	printf("集合B的元素为:");
	TraveList(B);
	AjiaoB(A,B);
	printf("A集合和B集合的交集为:\n");
	TraveList(A);
	return 0;
}