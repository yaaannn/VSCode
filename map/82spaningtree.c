/* ��С������.c */
#include "consts.h"
#define MAXVEX 30
#define MAXNAME 20/*������Ϣ�������ֵ*/
#define MAX 32767/*���������·�����Դ����ֵ��ʾ��ͨ*/
typedef char VexType[MAXNAME];/*������Ϣ*/
typedef float AdjType;/*��������Ȩֵ��Ϣ*/
typedef struct/*�߽ṹ��*/
{
    int start_vex, stop_vex;        /* �ߵ������յ� */
    AdjType weight;                 /* �ߵ�Ȩ */
} Edge;
typedef struct/*ͼ�ṹ*/
{
    int vexNum;                     /* ͼ�Ķ������ */
	int edgeNum;					/*ͼ�бߵ���Ŀ*/
	Edge mst[MAXVEX-1];				/*���ڱ�����С�������ı�����,ֻ�õ� ������-1 ��*/

    VexType vexs[MAXVEX];			/*������Ϣ */
    AdjType arcs[MAXVEX][MAXVEX];   /* �ߵ��ڽӾ��� */
} GraphMatrix;
int LocateVex(GraphMatrix *g, VexType u)/*�������: ��g�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1*/
 {
   int i;
   for(i=0;i<g->vexNum;++i)
     if(strcmp(u,g->vexs[i])==0)
       return i;
   return ERROR;
 }
void GraphInit(GraphMatrix *g)/*�ð���ͼ����Ϣ���ļ���ʼ��ͼ*/
{
	int i,j,t;
	float w;/*�ߵ�Ȩֵ*/
	VexType va,vb;/*���ڶ�λͼ�Ķ���(�ַ���)���ڽӾ����е��±�*/
	FILE *fp;
    fp=fopen("spaningtree.txt","r");
	fscanf(fp,"%d",&g->vexNum);/*����ͼ�Ķ������ͱ���*/
	fscanf(fp,"%d",&g->edgeNum);
	for(i=0;i<g->vexNum;i++)/*��ʼ���ڽӾ���*/
		for(j=0;j<=i;j++)
			g->arcs[i][j]=g->arcs[j][i]=MAX;
	for(i=0;i<g->vexNum;i++)/*���ļ����붥����Ϣ*/
		fscanf(fp,"%s",g->vexs[i]);
	for(t=0;t<g->edgeNum;t++)/*��λ���߲���Ȩֵ*/
	{
		fscanf(fp,"%s%s%f",va,vb,&w);
		i=LocateVex(g,va);
		j=LocateVex(g,vb);
		g->arcs[i][j]=g->arcs[j][i]=w;
	}
	fclose(fp);
}
void Prim(GraphMatrix * pgraph)/* ���ڽӾ�����ͼ����С������-����ķ�㷨*/
{
    int i, j, min;
	int vx, vy; /*��ʼ,��ֹ��*/
    float weight, minweight; 
	Edge edge;/*���ڽ�����*/
    for (i = 0; i < pgraph->vexNum-1; i++)/*��ʼ����С�������ߵ���Ϣ*/
	{
        pgraph->mst[i].start_vex = 0;/*��ʼ��Ϊ0�Ŷ���*/
        pgraph->mst[i].stop_vex = i+1;/*��ֹ��Ϊ����������*/
        pgraph->mst[i].weight = pgraph->arcs[0][i+1];/*ȨֵΪ0�Ŷ��㵽�����������·��Ȩֵ,��·����ΪMAX*/
    }
    for (i = 0; i < pgraph->vexNum-1; i++)/* ��n-1���� */
	{
        minweight = MAX;  min = i;
        for (j = i; j < pgraph->vexNum-1; j++)/* �����б�(vx,vy)(vx��U,vy��V-U)��ѡ����̵ı� */
            if(pgraph->mst[j].weight < minweight)
			{
                minweight = pgraph->mst[j].weight; 
                min = j;
            }
        /* mst[min]����̵ı�(vx,vy)(vx��U, vy��V-U)����mst[min]������С������ */
        edge = pgraph->mst[min];  
        pgraph->mst[min] = pgraph->mst[i];   
        pgraph->mst[i] = edge;
        vx = pgraph->mst[i].stop_vex;            /* vxΪ�ռ�����С�������Ķ�����±� */
        for(j = i+1; j < pgraph->vexNum-1; j++) /* ����mst[i+1]��mst[n-1] */
		{ 
            vy=pgraph->mst[j].stop_vex;
			weight = pgraph->arcs[vx][vy];
            if (weight < pgraph->mst[j].weight) 
			{
                pgraph->mst[j].weight = weight;  
                pgraph->mst[j].start_vex = vx;
            }
        }
    }
}
int main(int argc, char* argv[])
{
    int i;
	float totallen=0;
	GraphMatrix graph;
	GraphInit(&graph);/*��ͼ��Ϣ�ļ���ʼ��ͼ*/
    Prim(&graph);/*������ķ�㷨�����ͼ����С������*/
	printf("\n  Ӧ�������µ���·��!!\n\n");
    for (i = 0; i < graph.vexNum-1; i++)/*��ӡ��������Ϣ*/
	{
		printf("  %s<->%s��,%.2f����)\n", graph.vexs[graph.mst[i].start_vex],graph.vexs[graph.mst[i].stop_vex], graph.mst[i].weight);
		totallen+=graph.mst[i].weight;
	}
	printf("\n  ��·�߳�%f����\n",totallen);
	getchar();
	return 0;
}
