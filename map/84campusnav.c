/* ��������·���Ͻ�˹�����㷨 */
#include "consts.h"
#define MAXVEX  30                        
#define MAXNAME 20

typedef char VexType[MAXNAME];
typedef int AdjType;

typedef struct
{
    int n;                                           /* ͼ�Ķ������ */
    VexType vexs[MAXVEX];                   /* ������Ϣ */
    AdjType arcs[MAXVEX][MAXVEX];           /* ����Ϣ */
} GraphMatrix;

typedef struct/* �������·���Ľṹ�� */
{
    AdjType len;/* ���·������ */
    int pre;/* ǰһ���� */
}Path;

int LocateVex(GraphMatrix *g, VexType u)/*��ͼg�в��Ҷ���u�ı��*/
 {    
   int i;
   for(i=0;i<g->n;++i)
     if(strcmp(u,g->vexs[i])==0)
       return i;
   return ERROR;
 }

void Init(GraphMatrix *g)/* ��ʼ��������,����У԰��ͼ�ļ� */
{
	int i,j,k,w;
	int edgeNums;/*���бߵ�����*/
	VexType va,vb;/*��λ�ߵ���������*/
	FILE *graphlist;
	graphlist=fopen("campusnav.txt","r");/*�������ļ�,����graphlist��ʾ*/
	fscanf(graphlist,"%d",&g->n);/*�������Ķ������*/
	fscanf(graphlist,"%d",&edgeNums);
	for(i=0;i<g->n;++i) /*���춥������*/
		fscanf(graphlist,"%s",g->vexs[i]);
	for(i=0;i<g->n;++i) /*��ʼ���ڽӾ���*/
		for(j=0;j<g->n;++j)
			g->arcs[i][j]=INT_MAX; /*��Ȩֵ��������·������·��Ϊ����*/
	for(k=0;k<edgeNums;++k)
	{
		fscanf(graphlist,"%s%s%d",va,vb,&w);
		i=LocateVex(g,va);
		j=LocateVex(g,vb);
		if(i!=ERROR && j!=ERROR)/*�������������д���*/
			g->arcs[i][j]=w; /*������*/
		else 
		{
			printf("%s<->%s��ȡ����,������ϸ���!!",va,vb);
			exit(0);
		}
	}
	for(i=0;i<g->n;i++)/* ���㵽�����ȨֵΪ0 */
		g->arcs[i][i]=0;
   fclose(graphlist); /*�ر������ļ�*/
}

void Dijkstra(GraphMatrix *pgraph, Path dist[],int start)
{
    int i, j, min;
 	AdjType minw;
	dist[start].len=0;
	dist[start].pre=0; 
	pgraph->arcs[start][start]=1;/* ��ʾ����start�ڼ���U�� */
	
	for(i=0; i<pgraph->n; i++)/* ��ʼ������V-U�ж���ľ���ֵ */
	{		
		dist[i].len=pgraph->arcs[start][i];/* ��ʼ����Ϊ������ʼ�㵽������ıߵ�Ȩֵ */ 
		if(dist[i].len!=INT_MAX)/* ���ߴ����򶥵�i��ǰ������Ϊstart,���򲻴�����Ϊ-1 */
			dist[i].pre=start;
		else
			dist[i].pre= -1;
	}
	dist[start].pre = -1;/* �������ǰ����Ϊ-1 */
	for(i=0; i<pgraph->n; i++)
	{
		minw=INT_MAX;
		min=start;
		for(j=0; j<pgraph->n; j++)
		if( (pgraph->arcs[j][j]==0) && (dist[j].len<minw) ) /*��V-U��ѡ������ֵ��С����*/
		{
			minw=dist[j].len; 
			min=j;  
		}
		if(min==0) /* û��·������ͨ������V-U�еĶ��� */
			break;			
		pgraph->arcs[min][min]=1;	/* ����V-U��·����С�Ķ���Ϊmin,�÷��ʱ�־ */
		for(j=0; j<pgraph->n; j++)/* ��������V-U�еĶ�������·�� */
		{			
			if(pgraph->arcs[j][j]==1)/* �ö����Ѿ�����,�����ٿ��� */
				continue;
			if(dist[j].len>dist[min].len+pgraph->arcs[min][j] && dist[min].len+pgraph->arcs[min][j]>0)
			{
				dist[j].len=dist[min].len+pgraph->arcs[min][j];
				dist[j].pre=min;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	GraphMatrix graph;
	Path path[MAXVEX];
	int tmp,cnt=0,pre=-1;
	int temppath[MAXVEX];
	int m,n;
	VexType va,vb;/* ����ѯ�������ص� */
	long totallen=0;/*��·������*/
	long curlen=0;/*��ǰ·������*/
    Init(&graph);

	printf("\n  ��������Ҫ��ѯ�������յ�\n  ");
	scanf("%s%s",va,vb);
	m=LocateVex(&graph,va);/*����ͼ�е���������*/
	n=LocateVex(&graph,vb);
	if(m!=ERROR && n!=ERROR)/*�������㶼��ͼ�У����ҳ����߼����·�����*/
	{	
		Dijkstra(&graph, path,m);
		/* ��Ϊ��õ�·���϶����Ǵ��յ��Ƶ����,���ڽ�֮���� */
		for(tmp=0;tmp<MAXVEX;tmp++)
			temppath[tmp]=-1;
		pre=n;
		while(path[pre].pre!=-1)
		{
			temppath[cnt]=pre;/* �������򶥵����� */
			pre=path[pre].pre;
			cnt++;
		}
		temppath[cnt]=m;

		if(cnt<=0)/* û��·�� */
			if(m!=n)
				printf("%s->%s��·����\n!",graph.vexs[m],graph.vexs[n]);
			else
				printf("������Ķ����غ�!\n");
		else
		{
			tmp=cnt;
			printf("%s->",graph.vexs[temppath[tmp]]);
			for(;tmp>0;tmp--)
			{
				printf("%s(%d)->",graph.vexs[temppath[tmp-1]],graph.arcs[temppath[tmp]][temppath[tmp-1]]);
				totallen+=graph.arcs[temppath[tmp]][temppath[tmp-1]];
			}
			printf("��:%d\n",totallen);
		}
	}
	else
		printf("(%s<->%s)���в����ڵĳ���,������ϸ���!!",va,vb);
    return 0;
}

