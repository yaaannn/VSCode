typedef struct LQNode/* ���ӽ��ṹ */
{ 		
    DataType    info;
    struct LQNode *next;
}LQNode;

typedef struct/* ���Ӷ������Ͷ��� */
{		
    struct LQNode  *front;  		/* ͷָ�� */
    struct LQNode  *rear;  		/* βָ�� */
}LinkQueue;

