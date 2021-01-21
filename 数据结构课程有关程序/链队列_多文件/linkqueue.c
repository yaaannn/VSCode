LinkQueue  *LQueueCreateEmpty()/*����������,����ͷָ��*/
{ 	
    LinkQueue *plq = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (plq != NULL)
        plq->front = plq->rear = NULL;
    else
	{
		printf("�ڴ治��!! \n");
		return NULL;
	}	
    return plq;
}

 
int  LQueueIsEmpty( LinkQueue *plq )/*�ж����ӱ�ʾ�����Ƿ�Ϊ�ն���*/
{
    return (plq->front == NULL);
}



void  LQueueEnQueue( LinkQueue *plq, DataType x)/*������*/
{ 
    LQNode *p = (LQNode *)malloc(sizeof(LQNode));
    if ( p == NULL  )
        printf("�ڴ����ʧ��!\n");
    else 
	{ 
        p->info = x;
        p->next = NULL;
        if (plq->front == NULL)/*ԭ��Ϊ�ն�*/
            plq->front = p;
        else
            plq->rear->next = p;
        plq->rear = p;
    }
}


int  LQueueDeQueue( LinkQueue *plq,DataType * x)/*������*/
{ 
    LQNode *p;
    if( plq->front == NULL )
	{
		printf( "���п�!!\n " );
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
DataType  LQueueFront(LinkQueue *plq )/* �ڷǿն��������ͷԪ�� */
{ 
    return (plq->front->info);
}

