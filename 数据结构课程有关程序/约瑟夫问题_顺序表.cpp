#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int DataType;

//顺序表结构体定义
typedef struct node
{
    DataType data[MAXSIZE];
    int length;
}SeqList,*PSeqList;

//函数声明区
PSeqList Init_SeqList(void);//顺序表初始化
int Delete_SeqList(PSeqList PL,int i);//删除顺序表中的第i个元素
void Destroy_SeqList(PSeqList *PL);//销毁顺序表
int josephus_Seqlist(PSeqList josephus_Seq,int s,int m);//约瑟夫问题算法

PSeqList Init_SeqList()
{
    PSeqList PL;
    PL=(PSeqList)malloc(sizeof(SeqList));
    if(PL)
        PL->length=0;
    return PL;
}

int Delete_SeqList(PSeqList PL,int i)
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
    for (j=i;j<PL->length;j++)
    {
        PL->data[j-1]=PL->data[j];
    }
    PL->length--;
    return 1;
}

void Destroy_SeqList(PSeqList *PL)
{  
    if (*PL)
        free (*PL) ;
    *PL=NULL; 
    printf("顺序表已销毁\n");
    return ;
} 

int josephus_Seqlist(PSeqList josephus_Seq,int s,int m)
{
    for(int i=0;i<josephus_Seq->length;i++)
    {
        josephus_Seq->data[i]=i+1;
    }
    int s1,i,w;
    if(!josephus_Seq->length)
    {
        printf("表中无元素!");
        return 0;
    }
    s1=s-1;
    printf("输出约瑟夫序列:\n");
    for(i=josephus_Seq->length;i>0;i--)
    {
        s1=(s1+m-1)%i;
        w=josephus_Seq->data[s1];
        printf("%d\t",w);
        Delete_SeqList(josephus_Seq,s1+1);
    }
    printf("\n");
    return 1;
}

int main()
{
    int s,m;
    PSeqList josephus_Seq=Init_SeqList();//创建约瑟夫环
    printf("一共有n人,从第s人开始报数,数到m的人出局，请依次输入n,s,m:\n");
    scanf("%d%d%d",&josephus_Seq->length,&s,&m);
    josephus_Seqlist(josephus_Seq,s,m);//约瑟夫问题求解
    Destroy_SeqList(&josephus_Seq);//销毁约瑟夫序列
    return 0;
}
