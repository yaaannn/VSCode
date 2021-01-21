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

