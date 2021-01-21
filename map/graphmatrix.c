/*��������ͼ,����ͼ,�������뽨���������ķ������ơ�����ͼ���轫Ȩֵ��Ϊ1
����ͼ���轫ȨֵΪ1(������Ҫ����Ȩֵ)�ұ߲��Գ�,��g->arcs[i][j]=1;���������Ǳ߲��Գ�*/
void MUDGCreate(GraphMatrix *g)/*����������*/
{
	int i,j,k,t;
	float w;/*Ȩֵ*/
	printf("\n�������������Ķ���ĸ���(������%d��)\n",MAXVEX);
	scanf("%d",&g->vexNum);
	printf("\n������ͼ�ĸ��������������Ϣ(��v1)!\n");
	getchar(); /*ȥ���س�*/
	for(i=0;i<g->vexNum;i++)/*�����������Ϣ*/
		gets(g->vexs[i]);
	for(i=0;i<g->vexNum;i++)/*��ʼ���ڽӾ���*/
		for(j=0;j<g->vexNum;j++)
			g->arcs[i][j]=0;/*��0��ʾ�������û��·��,�Ҽٶ�ĳ�������ָ���Լ��Ļ�*/
	printf("\n����������бߵ���Ŀ(������%d��)\n",g->vexNum*(g->vexNum-1)/2);
	scanf("%d",&k);/*����ߵ���Ŀ*/
	for(t=0;t<k;t++)
	{
		printf("\n�������%d���ߵ������Ϣ(��ʼ����(��Ŵ�0��ʼ) ��ֹ���� Ȩֵ,��0 3 10.5)\n",t+1);
		scanf("%d%d%f",&i,&j,&w);
		g->arcs[i][j]=w;/*�������Գ�*/
		g->arcs[j][i]=w;
	}
}
int MUDGFirstVertex(GraphMatrix* pgraph) /*��ͼ�ĵ�һ������*/
{    
    return pgraph->vexNum == 0 ? ERROR : 0;
}
int MUDGNextVertex(GraphMatrix* pgraph,int i)/*��ͼ������ڶ���i����һ������*/
{    
    return i == pgraph->vexNum-1 ? ERROR : i+1;
}
int MUDGFirstAdjacent(GraphMatrix* pgraph, int i)/*��ͼ����i�ڽӵĵ�һ������*/
{
    int k;
    for (k = 0; k < pgraph->vexNum; k++)
        if(pgraph->arcs[i][k] != 0) return k;
    return ERROR; 
} 
int  MUDGNextAdjacent(GraphMatrix* pgraph, int i, int j)/*��ͼ�ж���i����ڶ���j����һ���ڽӶ���*/
{
    int k;
    for (k = j+1; k < pgraph->vexNum; k++)
        if (pgraph->arcs[i][k] != 0) return k;
    return ERROR; 
}   
int MUDGLocateVex(GraphMatrix *g, VexType u)/*�������: ��g�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1*/
 {
   int i;
   for(i=0;i<g->vexNum;++i)
     if(strcmp(u,g->vexs[i])==0)
       return i;
   return ERROR;
 }
/*******************������ͼ������ȱ�����������,��Ҫ��϶���ʹ��**********************/

void MUDGbfs( GraphMatrix* g , DataType v ,int visited[])/*��ͨͼ���ڽӾ����ʾ�Ĺ�����ȱ���*/
{	/*vistied���飬����ͼ�ı�����־�����Ƿ񱻷��ʹ�*/
    DataType v1 , v2;
    SeqQueue *q = SQueueCreate();       /*˳�����Ԫ�ص�����ΪDataType*/
    SQueueEnQueue( q, v ) ;/*��ʼ�������*/
    printf("%d ", v);
    visited[v] = TRUE ;/*��ʼ���㱻���ʹ�*/
    while ( !SQueueIsEmpty(q) )
	{
        SQueueDeQueue(q,&v1);/*��ͷԪ�س���,������ͷԪ�ر��� ��V1��*/
        v2 = MUDGFirstAdjacent ( g, v1 );
        while ( v2!= ERROR )/*�ڽӶ������ʱѭ��*/
		{
            if ( visited[v2] == FALSE )/*���ڽӶ���δ����������ӣ��ñ�־*/
			{
                SQueueEnQueue( q,  v2 );
                visited[v2] = TRUE ;
                printf("%d ", v2);
            }
            v2 = MUDGNextAdjacent( g, v1 , v2 ) ;/*ȡ��һ����*/
        }
    }
}
void MUDGbft(GraphMatrix* g,int visited[] )/*����ͨͼ�Ĺ�����ȱ���*/
{
    DataType v ;
    for ( v =MUDGFirstVertex ( g ) ; v != ERROR ; v = MUDGNextVertex ( g , v ) )
        if ( visited[v] == FALSE ) MUDGbfs( g , v,visited) ;/*����v��ÿһ��δ�����ڽӵ�ݹ����*/ 
} 
/********************************************************************/
/*************������ͼ��������ȱ�����������,��Ҫ��϶���ʹ��****************/
void MUDGdfs( GraphMatrix* g , DataType v,int visited[] )/*��ͨͼ��������ȱ���*/ 
{
    DataType v1;
    visited[v] = TRUE ;/*�÷��ʱ�־*/ 
    printf("%d ",v);
    for ( v1 = MUDGFirstAdjacent(g , v); v1 != ERROR ; v1=MUDGNextAdjacent(g ,v, v1) )
        if(visited[v1]==FALSE) MUDGdfs( g ,v1,visited );/*����v��ÿһ��δ�����ڽӵ�ݹ����*/
}
void MUDGdft( GraphMatrix* g ,int visited[]) /*����ͨͼ��������ȱ���*/
{
    DataType v ;
    for ( v =MUDGFirstVertex ( g ) ; v != ERROR ; v = MUDGNextVertex ( g , v ) )
        if ( visited[v] == FALSE ) MUDGdfs( g , v,visited ) ;/*��ͼ��ÿһ��δ���ʶ���ݹ����*/
}
/********************************************************************/
