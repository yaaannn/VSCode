/*已知线性表（a1，a2，a3 …an）按顺序存于内存，每个元素都是整数，
试设计用最少时间把所有值为负数的元素移到全部非负值元素前边的算法：
例:(x,-x,-x,x,x,-x …x)*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct node {
	int data[MAXSIZE];
	int length;
}SeqList, * PSeqList;

//创建线性表
PSeqList Init_SeqList()
{ 
	int i;
	PSeqList L;
	L=(PSeqList)malloc(sizeof(SeqList)); 
	printf("请输入线性表的长度:\n"); 
	scanf("%d",&L->length); 
	printf("请输入线性表的元素:\n",L->length); 
	for(i=0;i<L->length;i++) 
	scanf("%d",&L->data[i]); 
	return L; 
}

//排序算法
void Divide(PSeqList L) 
{   
    
	int low,high,tmp;
    low = 0;                      
	high=L->length-1;  
	while (low<high) 
	{
		while (low<high && L->data[high]>=0)  
		high--;
		while (low<high && L->data[low]<0)  
		low++;
       	if (low<high) 
		{  
			tmp=L->data[low];
			L->data[low]=L->data[high];
			L->data[high]=tmp;
		}
	}
}
//输出线性表
void Output_SeqList(PSeqList L)  
{ 
	int i;
	printf("排序结果为:\n"); 
	for(i=0;i<L->length;i++) 
	printf("%2d ",L->data[i]); 
}

int main() 
{ 
	PSeqList L; 
	L=Init_SeqList(); 
	Divide(L); 
	Output_SeqList(L); 
	return 0;
}
