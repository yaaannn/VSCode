#include "stdio.h"
#include "stdlib.h"
#define MaxVerNum 100 /* 最大顶点数为*/
typedef enum
{
    False,
    True
} boolean;
boolean visited[MaxVerNum];
typedef struct node /* 表结点*/
{
    int adjvex; /* 邻接点域,一般是放顶点对应的序号或在表头向量中的下标*/
    char Info; /*与边(或弧)相关的信息*/
    struct node *next; /* 指向下一个邻接点的指针域*/
} EdgeNode;

typedef struct vnode /* 顶点结点*/

{

    char vertex; /* 顶点域*/

    EdgeNode *firstedge; /* 边表头指针*/

} VertexNode;

typedef struct

{

    VertexNode adjlist[MaxVerNum]; /* 邻接表*/

    int n, e; /* 顶点数和边数*/

} ALGraph; /* ALGraph是以邻接表方式存储的图类型*/

//建立一个无向图的邻接表存储的算法如下：

void CreateALGraph(ALGraph *G) /* 建立无向图的邻接表存储*/

{

    int i, j, k;

    int N, E;

    EdgeNode *p;

    printf("请输入顶点数和边数：");

    scanf("%d %d", &G->n, &G->e);

    printf("n=%d,e=%d\n\n", G->n, G->e);

    getchar();

    for (i = 0; i < G->n; i++) /* 建立有n个顶点的顶点表*/

    {

        printf("请输入第%d个顶点字符信息(共%d个)：", i + 1, G->n);

        scanf("%c", &(G->adjlist[i].vertex)); /* 读入顶点信息*/

        getchar();

        G->adjlist[i].firstedge = NULL; /* 顶点的边表头指针设为空*/
    }

    for (k = 0; k < 2 * G->e; k++) /* 建立边表*/

    {

        printf("请输入边<Vi,Vj>对应的顶点序号(共%d个)：", 2 * G->e);

        scanf("%d %d", &i, &j); /* 读入边<Vi,Vj>的顶点对应序号*/

        p = (EdgeNode *)malloc(sizeof(EdgeNode)); // 生成新边表结点p

        p->adjvex = j; /* 邻接点序号为j */

        p->next = G->adjlist[i].firstedge; /* 将结点p插入到顶点Vi的链表头部*/

        G->adjlist[i].firstedge = p;
    }

    printf("\n图已成功创建!对应的邻接表如下：\n");

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

} /*CreateALGraph*/

int FirstAdjVertex(ALGraph *g, int v) //找图g中与顶点v相邻的第一个顶点

{

    if (g->adjlist[v].firstedge != NULL)
        return (g->adjlist[v].firstedge)->adjvex;

    else
        return 0;
}

int NextAdjVertex(ALGraph *g, int vi, int vj) //找图g中与vi相邻的,相对相邻顶点vj的下一个相邻顶点

{

    EdgeNode *p;

    p = g->adjlist[vi].firstedge;

    while (p != NULL && p->adjvex != vj)
        p = p->next;

    if (p != NULL && p->next != NULL)
        return p->next->adjvex;

    else
        return 0;
}

void DFS(ALGraph *G, int v) /* 从第v个顶点出发深度优先遍历图G */

{

    int w;

    printf("%c ", G->adjlist[v].vertex);

    visited[v] = True; /* 访问第v个顶点,并把访问标志置True */

    for (w = FirstAdjVertex(G, v); w; w = NextAdjVertex(G, v, w))

        if (!visited[w])
            DFS(G, w); /* 对v尚未访问的邻接顶点w递归调用DFS */
}

void DFStraverse(ALGraph *G)

/*深度优先遍历以邻接表表示的图G,而以邻接矩阵表示时,算法完全相同*/

{
    int i, v;

    for (v = 0; v < G->n; v++)

        visited[v] = False; /*标志向量初始化*/

    //for(i=0;i<G->n;i++)

    if (!visited[0])
        DFS(G, 0);

} /*DFS*/

int main()

{

    ALGraph G;

    CreateALGraph(&G);

    printf("该无向图的深度优先搜索序列为：");

    DFStraverse(&G);

    printf("\nSuccess!\n");
    return 0;
}
