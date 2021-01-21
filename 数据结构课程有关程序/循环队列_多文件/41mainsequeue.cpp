#include "consts.h"
#define MAXNUM 100
typedef int DataType;
#include "sequeue.h"
#include "sequeue.c"
int main(int argc,char *argv[])
{
	SeqQueue *psq=NULL;
	int   read=0 ;
	DataType x;
	do
	{
		puts("		关于循环队列的操作\n");
		puts("	     ======================\n");
		puts("		1 ------ 置空队");
		puts("		2 ------ 入队");
		puts("		3 ------ 出队");
		puts("		4 ------ 判断空队");
		puts("		5 ------ 输出");
		puts("		0 ------ 退出");
		puts("");
		printf("		请选择代号（0-5）");
		scanf("%d",&read);
		printf("\n");
		switch(read)
		{
			case  1  : 
				psq=SQueueCreate();
				break;
			case  2  : 
				printf("	输入入队数据元素:");
				scanf("%d",&x);
				SQueueEnQueue(psq,x);
				break;
			case  3  :
				if (SQueueDeQueue(psq,&x))
					printf("	出队数据元素是: %d\n",x);
				break;
			case  4  : 
				if(SQueueIsEmpty(psq))
					printf("队列已空!\n");
				else
					printf("队列不空!\n");
				break;
			case 5:
				printf("\n现在队列中的元素依次为：\n");
				SQueuePrint(psq);
				printf("\n");
				break;
			case  0  : 
				read=0 ;
				break;
			default : ;
		}
		getchar();
	}while(read!=0 );
	return 0;
}
