#include "consts.h"
#define MAXNAME 20/*������Ϣ��󳤶�*/
#define MAXVEX 30/*����������ֵ*/
#define MAXNUM 30  /* ���������Ԫ�ظ��� */
typedef int DataType;/*����Ԫ������*/
typedef char VexType[MAXNAME];/*������Ϣ*/
typedef float AdjType;/*Ȩֵ*/ 
#include "sequeue.h"
#include "sequeue.c"
#include "graphmatrix.h"
#include "graphmatrix.c"
int main(int argc, char* argv[])
{
	int i=0;
	int res;
	GraphMatrix g;
	GraphMatrix *pg=&g;
	int visited[MAXVEX];/*������־����*/
	for(;i<MAXVEX;i++)
		visited[i]=FALSE;
	printf("\n�������������ڽӾ���,��������б���!\n");
	MUDGCreate(pg);
	res=MUDGFirstVertex(pg);
	res=MUDGFirstAdjacent(pg,0);
	res=MUDGNextVertex(pg,0);
	res=MUDGNextAdjacent(pg,0,1);
	printf("\n�������Ϊ:\n");
	MUDGdft(pg,visited);/*������ȱ���*/
	return 0;
}

