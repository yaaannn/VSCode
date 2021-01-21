 #include<string.h>
 #include<malloc.h> /* malloc()等 */
 #include<limits.h> /* INT_MAX等 */
 #include<stdio.h> /* EOF(=^Z或F6),NULL */
 #include<stdlib.h> /* atoi() */
 #include<io.h> /* eof() */
 #include<math.h> /* floor(),ceil(),abs() */
 #include<process.h> /* exit() */

 /* 函数结果状态代码 */
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR -1
 #define INFEASIBLE -1

#define MAXNUM 100
typedef int DataType;
typedef  struct	/*顺序队列类型定义*/
{
   int front, rear;
   DataType data[MAXNUM];
}SeqQueue;

/* ① 置空队 */
SeqQueue *SQueueCreate()	/*创建一个空队列*/
{  
    SeqQueue *sq = (SeqQueue*)malloc(sizeof(SeqQueue));
    if (sq==NULL)
        printf("溢出!! \n");
    else
        sq->front = sq->rear = 0;
    return sq;
}
/* ② 判队空函数 */
int  SQueueIsEmpty( SeqQueue *sq )           	                   /*判队列是否为空队列*/ 
{
    if(sq->front == sq->rear)
        return TRUE;
    else 
        return FALSE;
}
/* ③ 进队 */
void  SQueueEnQueue( SeqQueue *sq, DataType x )      	    /* 循环队列的进队操作，x进队 */ 
{
    if( (sq->rear + 1) % MAXNUM == sq->front  )                	      /*  修改队尾指针  */
        printf( "队列满!\n" );
    else 	
    {
        sq->rear = (sq->rear + 1) % MAXNUM;
        sq->data[sq->rear] = x;
    }
}
/* ④ 出队 */
int  SQueueDeQueue( SeqQueue *sq ,DataType *e)	/* 循环队列的出队操作，出队元素存入e中 */ 
 {
    if( sq->front == sq->rear )
    {
        printf( "队空!\n" );
        return ERROR;
    }
    else
    { 
        sq->front = (sq->front + 1) % MAXNUM;       	              /*  修改队头指针  */
        *e=sq->data[sq->front];
        return OK;
    }
}
/* ⑤ 读对头元素 */
DataType  SQueueFront(SeqQueue *sq) 	  /*  读出队头元素，但队头指针保持不变 */
{
    if (sq->front == sq->rear)
    {
        printf("队空下溢\n");
        return ERROR;     	     /*  队列为空  */
    }
    else
        return(sq->data[(sq->front+1)%MAXNUM]);
}
/* ⑥ 输出循环队列 */
void SQueuePrint(SeqQueue *sq)   	                        /* 输出循环队列中所有元素 */ 
{
    int i=(sq->front+1)%MAXNUM;
    while(i!=sq->rear)
    {
        printf("\t%d ",sq->data[i]);
        i=(i+1) % MAXNUM;
    }
}
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
