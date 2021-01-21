/* ���������ڽӱ�.c */
#include "consts.h"
typedef int DataType;
#define MAXNUM 30/*˳��ջԪ�ظ������ֵ*/
#include "seqstack.h"
#include "seqstack.c"
#define MAXVEX 30/*ͼ�ж���������ֵ*/ 
#define MAXNAME 20/*ͼ�ж����������ֵ*/ 
#include "sequeue.h"/*ͼ�Ļ��������б�������ʹ���������ļ�*/ 
#include "sequeue.c" 
typedef char VexType[MAXNAME];/*������Ϣ*/
typedef float AdjType;/*Ȩֵ*/ 
#include "graphlist.h"
#include "graphlist.c" 

void LDGCreate(GraphList *g)/*��������ͼ���ڽӱ�*/
{
	int i,j,t;
	VexType va ,vb; 
	EdgeNode *s;
	FILE *fp;
    fp=fopen("topologysort.txt","r");
	fscanf(fp,"%d",&g->vexNum);/*����γ����������к�̹�ϵ��*/
	fscanf(fp,"%d",&g->edgeNum);
	for(i=0;i<g->vexNum;i++)
	{
		fscanf(fp,"%s",g->vexs[i].vertex);
		g->vexs[i].edgelist=NULL;
	}
	for(t=0;t<g->edgeNum;t++)/*������ſγ̵����к�̹�ϵ��*/
	{
		fscanf(fp,"%s%s",va,vb);
		s=(EdgeNode *)malloc(sizeof(EdgeNode));
		i=LUDGLocateVex(g,va);
		j=LUDGLocateVex(g,vb);
		s->endvex = j;
		s->nextedge=g->vexs[i].edgelist;
		g->vexs[i].edgelist=s;
	}
	fclose(fp);
}
void FindInDegree(GraphList g,int inDegree[])/*���ͼ�ĸ����������ȣ�������浽������*/
{
	int i;
	EdgeNode *p;
	for(i=0;i<g.vexNum;i++)/*��ʼ��*/
		inDegree[i]=0;
	for(i=0;i<g.vexNum;i++)
	{
		p=g.vexs[i].edgelist;/*ȡ����i�����㣬���ɸö����������Ļ�����Ӧ�Ļ�β������ȼ�1*/
		while(p)
		{
			inDegree[p->endvex]++;
			p=p->nextedge;/*ȡ��һ���Ըö���Ϊ��Ϊ�ı�*/
		}
	}
}
int TopologicalSort(GraphList g,int *res)
{
	int i,k,count=0;
	int inDegree[MAXVEX];/*�����������ȵ�����*/
	SeqStack s;/*˳��ջ��������Ϊ0�Ķ������*/
	EdgeNode *p;
	FindInDegree(g,inDegree);/*��������ǰ���������������Ϣ*/
	SStackSetNull(&s);
	for(i=0;i<g.vexNum;i++)/*�Ƚ����Ϊ0�Ķ�����ջ*/
		if(!inDegree[i])
			SStackPush(&s,i);
	while(!SStackIsEmpty(&s))/*ջ����ʱ��������������*/
	{
		SStackPop(&s,&i);/*ջ��Ԫ�س�ջ���ó�ջ���м�Ϊ�������������*/
		*res++=i;/*�����ջ��������*/
		count++;/*��ջ���������1*/
		for(p=g.vexs[i].edgelist;p;p=p->nextedge)/*���Ըö���Ϊ��β�ıߵĻ�ͷ������ȼ�1*/
		{
			k=p->endvex;
			if(!(--inDegree[k]))/*������󶥵����Ϊ0����ջ*/
				SStackPush(&s,k);
		}
	}
	if(count<g.vexNum)/*�л�·*/ 
		return ERROR;
	else
		return OK;
}

int main(int argc, char* argv[])
{
	int i,res[MAXVEX];/*���ڱ����������򶥵����е�����*/
	GraphList g;
	GraphList *pg=&g;
	LDGCreate(pg);
	for(i=0;i<MAXVEX;i++) res[i]=-1; 
	if(TopologicalSort(g,res))
	{
		printf("\n  ���԰�����˳���ſγ�!\n");
		printf("  "); 
		for(i=0;i<g.vexNum-1;i++)
		{   
			if(i%5==0)
			{
				printf("\n" );
				printf("  " );
			} 
			printf("%s->",g.vexs[res[i]].vertex);/*���������Ϣ*/

		} 
		printf("%s\n",g.vexs[res[i]].vertex);
	}
	else
		printf("\n  ������Ŀγ����к�̹�ϵ�д���(���ڻ�)!!\n");
		getchar();
	return 0;
}

