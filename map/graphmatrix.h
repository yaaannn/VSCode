typedef struct/*ͼ���ڽӾ������ݽṹ*/ 
{
    int vexNum;                                 /* ͼ�Ķ������ */
    VexType vexs[MAXVEX];                 /*  ������Ϣ */
    AdjType arcs[MAXVEX][MAXVEX];           /* ����Ϣ */
}GraphMatrix;
