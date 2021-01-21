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
 typedef int DataType;/*链队元素类型为整型*/
 typedef struct LQNode/* 链队结点结构 */
{ 		
    DataType    info;
    struct LQNode *next;
}LQNode;

typedef struct/* 链接队列类型定义 */
{		
    struct LQNode  *front;  		/* 头指针 */
    struct LQNode  *rear;  		/* 尾指针 */
}LinkQueue;
LinkQueue  *LQueueCreateEmpty()/*创建空链队,返回头指针*/
{ 	
    LinkQueue *plq = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (plq != NULL)
        plq->front = plq->rear = NULL;
    else
	{
		printf("内存不足!! \n");
		return NULL;
	}	
    return plq;
}

int  LQueueIsEmpty( LinkQueue *plq )/*判断链接表示队列是否为空队列*/
{
    return (plq->front == NULL);
}

void  LQueueEnQueue( LinkQueue *plq, DataType x)/*入链队*/
{ 
    LQNode *p = (LQNode *)malloc(sizeof(LQNode));
    if ( p == NULL  )
        printf("内存分配失败!\n");
    else 
	{ 
        p->info = x;
        p->next = NULL;
        if (plq->front == NULL)/*原来为空队*/
            plq->front = p;
        else
            plq->rear->next = p;
        plq->rear = p;
    }
}

int  LQueueDeQueue( LinkQueue *plq,DataType * x)/*出链队*/
{ 
    LQNode *p;
    if( plq->front == NULL )
	{
		printf( "队列空!!\n " );
		return ERROR;
	}
    else
	{ 
        p = plq->front;
		*x=p->info;
        plq->front = plq->front->next;
        free(p);
		return OK;
    }
}

DataType  LQueueFront(LinkQueue *plq )/* 在非空队列中求队头元素 */
{ 
    return (plq->front->info);
}

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




