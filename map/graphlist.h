typedef struct EdgeNode/*ͼ�ı߽ṹ����*/
{
    int endvex;			/* ���ڶ����ֶ� */
    AdjType weight;		/* �ߵ�Ȩ���Ǵ�Ȩͼ����ʡ�� */
    struct EdgeNode *nextedge;	/* ���ֶ� */
}EdgeNode;	                    /* �߱��еĽ�� */
typedef struct /*ͼ�Ķ���ṹ����*/
{
    VexType vertex;		/* ������Ϣ */
    EdgeNode *edgelist;	/* �߱�ͷָ�� */
} VexNode;               /* ������еĽ�� */
typedef struct /*ͼ�����ݽṹ����*/
{
	int vexNum;				/* ͼ�Ķ������ */
	int edgeNum;			/* ͼ�ıߵ����� */
	VexNode vexs[MAXVEX];
} GraphList;/*ͼ���ڽӱ�洢�ṹ*/
