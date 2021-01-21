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
		puts("		����ѭ�����еĲ���\n");
		puts("	     ======================\n");
		puts("		1 ------ �ÿն�");
		puts("		2 ------ ���");
		puts("		3 ------ ����");
		puts("		4 ------ �жϿն�");
		puts("		5 ------ ���");
		puts("		0 ------ �˳�");
		puts("");
		printf("		��ѡ����ţ�0-5��");
		scanf("%d",&read);
		printf("\n");
		switch(read)
		{
			case  1  : 
				psq=SQueueCreate();
				break;
			case  2  : 
				printf("	�����������Ԫ��:");
				scanf("%d",&x);
				SQueueEnQueue(psq,x);
				break;
			case  3  :
				if (SQueueDeQueue(psq,&x))
					printf("	��������Ԫ����: %d\n",x);
				break;
			case  4  : 
				if(SQueueIsEmpty(psq))
					printf("�����ѿ�!\n");
				else
					printf("���в���!\n");
				break;
			case 5:
				printf("\n���ڶ����е�Ԫ������Ϊ��\n");
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
