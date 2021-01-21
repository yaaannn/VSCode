#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef char DataType;
typedef struct bnode
{
    DataType data;
    struct bnode *lchild,*rchild;
}BNode,*BTree;

typedef struct elementype
{
    BNode *node;
    int flag;
}elementype;

typedef struct 
{
    elementype data[MAXSIZE];
    int top;
}SeqStack,*PSeqStack;

void Visit(BTree T)//输出结点
{
    if(T->data!='#')
    {
        printf("%c  ",T->data);
    }
}

PSeqStack Init_SeqStack(void)//初始化栈
{
    PSeqStack S;
    S=(PSeqStack)malloc(sizeof(SeqStack));
    if(S)
        S->top=-1;
    return S;
}

int Empty_SeqStack(PSeqStack S)//判栈空
{
    if(S->top==-1)
        return 1;
    else
        return 0;
}

int Push_SeqStack(PSeqStack S,elementype x)//入栈
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

int Pop_SeqStack(PSeqStack S,elementype *x)//出栈
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

BTree Pre_Creat_BT()//建立二叉树
{
    BTree BT;
    char ch;
    ch=getchar();
    if(ch=='#')
        return NULL;
    else
    {
        BT=(BTree)malloc(sizeof(BNode));
        BT->data=ch;
        BT->lchild=Pre_Creat_BT();
        BT->rchild=Pre_Creat_BT();
        return BT;
    }
}

void PreOrder(BTree t)//先序遍历的递归算法
{
    if(t)
    {
        Visit(t);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}

void InOrder(BTree t)//中序遍历的递归算法
{
    if(t)
    {
        InOrder(t->lchild);
        Visit(t);
        InOrder(t->rchild);
    }
}

void PostOrder(BTree t)//后序遍历的递归算法
{
    if(t)
    {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        Visit(t);
    }
}

void PreOrder_Nor(BTree t)//利用栈的先序遍历的非递归算法
{
    PSeqStack S;
    elementype Sq;
    BNode *p=t;
    S=Init_SeqStack();
    while (p||!Empty_SeqStack(S))   
    {
        if(p)
        {
            Visit(p);
            Sq.node=p;
            Push_SeqStack(S,Sq);
            p=p->lchild;   
        }
        else
        {
            Pop_SeqStack(S,&Sq);
            p=Sq.node;
            p=p->rchild;
        }
    }
}

void InOrder_Nor(BTree t)//利用栈的中序遍历非递归算法
{
    PSeqStack S;
    elementype Sq;
    BNode *p=t;
    S=Init_SeqStack();
    while (p||!Empty_SeqStack(S))   
    {
        if(p)
        {
            Sq.node=p;
            Push_SeqStack(S,Sq);
            p=p->lchild;   
        }
        else
        {
            Pop_SeqStack(S,&Sq);
            p=Sq.node;
            Visit(p);
            p=p->rchild;
        }
    }

}
void PostOrder_Nor(BNode *t)//利用栈的后序遍历非递归算法
{
    PSeqStack S;
    elementype Sq;
    BNode *p=t;
    S=Init_SeqStack();
    while (p||!Empty_SeqStack(S))   
    {
        if(p)
        {
            Sq.flag=0;
            Sq.node=p;
            Push_SeqStack(S,Sq);
            p=p->lchild;   
        }
        else
        {
            Pop_SeqStack(S,&Sq);
            p=Sq.node;
            if(Sq.flag==0)
            {
                Sq.flag=1;
                Push_SeqStack(S,Sq);
                p=p->rchild;
            }
            else
            {
                Visit(p);
                p=NULL;
            }
        }
    }
}

int main()
{
    BTree t;
    printf("输入构造一棵二叉树:");
    t=Pre_Creat_BT();
    printf("递归先序遍历:  ");
    PreOrder(t);
    printf("\n非递归先序遍历:");
    PreOrder_Nor(t);
    printf("\n递归中序遍历:  ");
    InOrder(t);
    printf("\n非递归中序遍历:");
    InOrder_Nor(t);
    printf("\n递归后序遍历:  ");
    PostOrder(t);
    printf("\n非递归后序遍历:");
    PostOrder_Nor(t);
    return 0;
}
/*
输入样例：AB#D##CE##F##
输出样例：
递归先序遍历:  A  B  D  C  E  F  
非递归先序遍历:A  B  D  C  E  F
递归中序遍历:  B  D  A  E  C  F
非递归中序遍历:B  D  A  E  C  F  
递归后序遍历:  D  B  E  F  C  A
非递归后序遍历:D  B  E  F  C  A
*/