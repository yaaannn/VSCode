void LUDGCreate(GraphList *g)/*�����������ڽӱ�*/
{
	int i,j,k;
	EdgeNode *s;
	float w;/*Ȩֵ*/
	printf("\n�������������Ķ���ĸ���(������%d��)\n",MAXVEX);
	scanf("%d",&g->vexNum);
	printf("\n���������и��������������Ϣ(��v1)!\n");
	getchar();/*ȥ���س���*/
	for(i=0;i<g->vexNum;i++)/*��ʼ��*/
	{
		gets(g->vexs[i].vertex);
		g->vexs[i].edgelist=NULL;
	}
	printf("\n����������бߵ���Ŀ(������%d��)\n",g->vexNum*(g->vexNum-1)/2);
	scanf("%d",&g->edgeNum);/*����ߵ���Ŀ*/
	for(k=0;k<g->edgeNum;k++)
	{
		printf("\n�������%d���ߵ������Ϣ(��ʼ����(��Ŵ�0��ʼ) ��ֹ���� Ȩֵ,��0 3 10.5)\n",k+1);
		scanf("%d%d%f",&i,&j,&w);/*����ߵ���ֹ�㼰Ȩֵ*/
		s=(EdgeNode *)malloc(sizeof(EdgeNode));/*���ɱ߽��*/
		s->endvex = j;
		s->nextedge=g->vexs[i].edgelist;
		s->weight=w;
		g->vexs[i].edgelist=s;
		s=(EdgeNode *)malloc(sizeof(EdgeNode));/*������,�߶Գ�*/
		s->endvex = i;
		s->nextedge=g->vexs[j].edgelist;
		s->weight=w;
		g->vexs[j].edgelist=s;
	}
}
int LUDGLocateVex(GraphList *g, VexType u)/*��g�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�ERROR*/
 { 
   int i;
   for(i=0;i<g->vexNum;++i)
     if(strcmp(u,g->vexs[i].vertex)==0)
       return i;
   return ERROR;
 }
int LUDGFirstVertex(GraphList* pgraph) /*����ͼ�ĵ�һ������*/
{    
    return pgraph->vexNum == 0 ? ERROR : 0;
}
int LUDGNextVertex(GraphList* pgraph,int i) /*��������ڶ���i����һ������*/
{    
    return i == pgraph->vexNum-1 ? ERROR : i+1;
}
int LUDGFirstAdjacent(GraphList* pgraph, int i)/*���Ҷ���i�ĵ�һ���ڽӶ���*/ 
{
    if (pgraph->vexs[i].edgelist != NULL)
        return pgraph->vexs[i].edgelist->endvex;
    else return ERROR; 
}  
int LUDGNextAdjacent(GraphList* pgraph, int i, int j) /*ͼ�ж���i����ڶ���j����һ���ڽӶ���*/
{
    EdgeNode *p;
    for (p = pgraph->vexs[i].edgelist; p != NULL; p = p->nextedge)
        if (p->endvex == j) {
            if (p->nextedge != NULL)
                return p->nextedge->endvex;
            else 
                return ERROR;
        }
    return ERROR; 
}   
void LUDGbfs( GraphList* g , DataType v ,int visited[]) /*��ͨͼ���ڽӱ�洢������ȱ���,��Ҫʹ�ö���*/
{	/*visited�������,���ڱ�Ƿ��ʹ��Ķ���*/
    DataType v1 , v2;
    SeqQueue *q = SQueueCreate( ) ;   /* ����Ԫ�ص�����ΪDataType* */
    SQueueEnQueue( q ,v ) ;/*��ʼ�������*/
    printf("%d ",v);
    visited[v] = TRUE ;/*�÷��ʱ�־*/
    while ( !SQueueIsEmpty(q) ) /*���в��������ѭ��*/
	{
        SQueueDeQueue( q,&v1 );/*��ͷԪ�س���*/
        v2 = LUDGFirstAdjacent ( g ,v1 );/*�ҵ�v1�ĵ�һ���ڽӶ���*/
        while ( v2 != ERROR )/*��v1���ڽӶ������*/
		{
            if ( visited[v2] == FALSE )/*δ���ʹ�,���÷��ʱ�־,ͬʱ���*/
			{
   	            SQueueEnQueue( q,  v2 );
                visited[v2] = TRUE ;
                printf("%d ",v2);
            }
            v2 = LUDGNextAdjacent ( g , v1 , v2 ) ;/*��ȡ��һ���ڽӶ���*/
        }
    }
}
void LUDGbft( GraphList* g,int visited[])/*����ͨͼ���ڽӱ�洢������ȱ���*/
{
    DataType v ;
    for ( v = LUDGFirstVertex ( g ) ; v != ERROR ; v = LUDGNextVertex ( g , v ) )
        if ( visited[v] == FALSE ) LUDGbfs ( g , v,visited ) ;/*��ͼ��ÿһ��δ���ʹ��Ķ���,�ݹ����*/
} 

void LUDGdfs(GraphList* g , DataType v,int visited[])/*��ͨͼ���ڽӱ��ʾ������ȱ���*/
{
	EdgeNode *p;
	printf("%d",v);/*���������Ϣ,�÷��ʱ�־*/
	visited[v]=TRUE;
	p=g->vexs[v].edgelist;/*ȡ���ڽӶ�������ͷ*/
	while(p!=NULL)/*�ڽӶ������*/
	{
		if(!visited[p->endvex])/*δ���ʹ���ݹ����*/
			LUDGdfs(g,p->endvex,visited);
		p=p->nextedge;/*ȡ��һ�ڽӶ���*/
	}
}
void LUDGdft( GraphList* g,int visited[] )/*����ͨͼ���ڽӱ��ʾ������ȱ���*/
{
    DataType v ;
    for ( v=0 ; v<g->vexNum ; v++ )/*��ͼ��ÿһ��δ���ʹ��Ķ���,�ݹ����*/
        if ( visited[v] == FALSE ) LUDGdfs ( g , v,visited ) ;
} 

