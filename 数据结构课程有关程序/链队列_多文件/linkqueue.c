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

