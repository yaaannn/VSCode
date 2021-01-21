#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 100
#define MaxVerNum 100
typedef enum
{
    False,
    True
} boolean;
boolean visited[MaxVerNum];

typedef struct /*顺序队列类型定义*/
{
    int data[MAXSIZE];
    int front, rear;
} SeqQueue, *PSeqQueue;

typedef struct node /*图的边结构定义*/
{
    int adjvex;
    char Info;
    struct node *next;
} EdgeNode;

typedef struct vnode /*图的顶点结构定义*/
{
    char vertex;
    EdgeNode *firstedge;
} VertexNode;

typedef struct /*图的数据结构定义*/
{
    VertexNode adjlist[MaxVerNum];
    int n, e;
} ALGraph;

PSeqQueue Init_SeqQueue() /*进队*/
{
    PSeqQueue Q;
    Q = (PSeqQueue)malloc(sizeof(SeqQueue));
    if (Q)
    {
        Q->front = 0;
        Q->rear = 0;
    }
    return Q;
}
int Empty_SeqQueue(PSeqQueue Q) /*判队空*/
{
    if (Q && Q->front == Q->rear)
        return 1;
    else
        return 0;
}
int In_SeqQueue(PSeqQueue Q, int x) /*入队*/
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        printf(" 队满");
        return -1;
    }
    else
    {
        Q->rear = (Q->rear + 1) % MAXSIZE;
        Q->data[Q->rear] = x;
        return 1;
    }
}
int Out_SeqQueue(PSeqQueue Q, int *x) /*出队*/
{
    if (Empty_SeqQueue(Q))
    {
        printf(" 队空");
        return -1;
    }
    else
    {
        Q->front = (Q->front + 1) % MAXSIZE;
        *x = Q->data[Q->front];
        return 1;
    }
}
void CreateALGraph(ALGraph *G) /*建立无向图的邻接表存储*/
{
    int i, j, k;
    EdgeNode *p;
    printf("请输入顶点数和边数： ");
    scanf("%d %d", &G->n, &G->e);
    printf("n=%d,e=%d\n\n", G->n, G->e);
    getchar();
    for (i = 0; i < G->n; i++)
    {
        printf("请输入第 %d 个顶点字符信息 (共%d 个)：", i + 1, G->n);
        scanf("%c", &(G->adjlist[i].vertex));
        getchar();
        G->adjlist[i].firstedge = NULL;
    }
    for (k = 0; k < 2 * G->e; k++)
    {
        printf("请输入边 <Vi,Vj> 对应的顶点序号 (共%d 个)：", 2 * G->e);
        scanf("%d %d", &i, &j);
        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex = j;
        p->next = G->adjlist[i].firstedge;
        G->adjlist[i].firstedge = p;
    }
    printf("\n图已成功创建 !对应的邻接表如下： \n");
    for (i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstedge;
        printf("%c->", G->adjlist[i].vertex);
        while (p != NULL)
        {
            printf("[ %c ]", G->adjlist[p->adjvex].vertex);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
}

void Visit(int v)
{
    printf(" %d,", v);
}

void BFS(ALGraph *G, int v)/* 从第v个顶点出发广度优先遍历图*/
{
    EdgeNode *p;
    int u, w;
    PSeqQueue Q;
    Q = Init_SeqQueue();
    Visit(v);
    visited[v] = True;
    In_SeqQueue(Q, v);
    while (!Empty_SeqQueue(Q))
    {
        Out_SeqQueue(Q, &u);
        for (p = G->adjlist[u].firstedge; p; p = p->next)
        {
            w = p->adjvex;
            if (!visited[w])
            {
                Visit(w);
                visited[w] = True;
                In_SeqQueue(Q, w);
            }
        }
    }
}

void BFStraverse(ALGraph *G)/*广度优先遍历*/
{
    int i, v;
    for (v = 0; v < G->n; v++)
        visited[v] = False;
    for (i = 0; i < G->n; i++)
        if (!visited[i])
            BFS(G, i);
}

int main()
{
    ALGraph G;
    CreateALGraph(&G);
    printf("该无向图的广度优先搜索序列为： ");
    BFStraverse(&G);
    printf("\nsuccess!\n\n");
    return 0;
}