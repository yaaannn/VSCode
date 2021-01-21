#include "consts.h"
typedef int DataType;/*链队元素类型为整型*/
#include "linkqueue.h"
#include "linkqueue.c"
int main(int argc,char *argv[])
{
	LinkQueue *p;
	int i;
	DataType x;
	p=LQueueCreateEmpty();
	for(i=0;i<10;i++)
		LQueueEnQueue(p,i);
	for(i=0;i<10;i++)
	{
		if(LQueueDeQueue(p,&x))
			printf("\n%d",x);
	}
	return 0;
}

