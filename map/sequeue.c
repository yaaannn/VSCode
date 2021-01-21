/* �� �ÿն� */
SeqQueue *SQueueCreate()	/*����һ���ն���*/
{  
    SeqQueue *sq = (SeqQueue*)malloc(sizeof(SeqQueue));
    if (sq==NULL)
        printf("���!! \n");
    else
        sq->front = sq->rear = 0;
    return sq;
}
/* �� �жӿպ��� */
int  SQueueIsEmpty( SeqQueue *sq )           	                   /*�ж����Ƿ�Ϊ�ն���*/ 
{
    if(sq->front == sq->rear)
return TRUE;
else 
return FALSE;
}
/* �� ���� */
void  SQueueEnQueue( SeqQueue *sq, DataType x )      	    /* ѭ�����еĽ��Ӳ�����x���� */ 
{
    if( (sq->rear + 1) % MAXNUM == sq->front  )                	      /*  �޸Ķ�βָ��  */
        printf( "������!\n" );
    else 	
{
sq->rear = (sq->rear + 1) % MAXNUM;
sq->data[sq->rear] = x;
    }
}
/* �� ���� */
int  SQueueDeQueue( SeqQueue *sq ,DataType *e)	/* ѭ�����еĳ��Ӳ���������Ԫ�ش���e�� */ 
 {
    if( sq->front == sq->rear )
    {
printf( "�ӿ�!\n" );
return ERROR;
}
    else
{ 
         sq->front = (sq->front + 1) % MAXNUM;       	              /*  �޸Ķ�ͷָ��  */
*e=sq->data[sq->front];
return OK;
}
}
/* �� ����ͷԪ�� */
DataType  SQueueFront(SeqQueue *sq) 	  /*  ������ͷԪ�أ�����ͷָ�뱣�ֲ��� */
{
if (sq->front == sq->rear)
{
  printf("�ӿ�����\n");
          return ERROR;     	     /*  ����Ϊ��  */
}
else
return(sq->data[(sq->front+1)%MAXNUM]);
}
/* �� ���ѭ������ */
void SQueuePrint(SeqQueue *sq)   	                        /* ���ѭ������������Ԫ�� */ 
{
int i=(sq->front+1)%MAXNUM;
while(i!=sq->rear)
{
printf("\t%d ",sq->data[i]);
i=(i+1) % MAXNUM;
}
}
