#include "consts.h" 
#define MAXNUM 30 /*����Ԫ�����ֵΪ30*/
#define MAXVEX 30/*�ڽӱ��ж���������ֵ*/ 
#define MAXNAME 20/*�ڽӱ��ж����������ֵ*/
typedef int DataType;/*����Ԫ������Ϊ����*/
#include "sequeue.h"
#include "sequeue.c"
typedef char VexType[MAXNAME];/*�������Ϣ��*/
typedef float AdjType;/*�ߵ���Ϣ,һ��ΪȨֵ*/
#include "graphlist.h"
#include "graphlist.c"
 
int main(int argc, char* argv[])
{
	int i=0;
	int res;
	GraphList g;
	GraphList *pg=&g;
	int visited[MAXVEX];/*������־����*/
	for(;i<MAXVEX;i++)
		visited[i]=FALSE;
	printf("\n�������������ڽӱ�,��������б���!\n");
	LUDGCreate(pg);
	res=LUDGFirstVertex(pg);
	res=LUDGFirstAdjacent(pg,0);
	res=LUDGNextVertex(pg,0);
	res=LUDGNextAdjacent(pg,0,1);
	printf("\n�������Ϊ:\n");
	LUDGdft(pg,visited);
	return 0;
}
