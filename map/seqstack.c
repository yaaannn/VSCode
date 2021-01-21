void SStackSetNull(SeqStack *s)   /*�ÿ�ջ*/
{
    s->top =-1;
}

int SStackIsEmpty(SeqStack *s)    /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
    return(s->top<0?TRUE:FALSE);
}

int SStackIsFull(SeqStack *s)        /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
    return(s->top==MAXNUM-1?TRUE:FALSE);
}


int SStackPush(SeqStack *s, DataType x)
{
    if (s->top==MAXNUM-1)
    {
        printf("ջ�����!\n");
        return FALSE;
    }
    else
    {
        s->top = s->top + 1;
        s->data[s->top]=x;
        return TRUE;
    }
}


int SStackPop(SeqStack *s, DataType *x)
{
    if (s->top==-1)
    {
        printf("ջ�����!\n");
        return FALSE;
    }
    else
    {
        *x=s->data[s->top];
        s->top--;
        return TRUE;
    }
}

DataType SStackGetTop(SeqStack *s)
{
    if (s->top ==-1)
    {
        printf("ջ�����!\n");
        return FALSE;
    }
    else
        return (s->data[s->top]);
}
void SStackPrint(SeqStack  *s)
{
    int p;
    if(SStackIsEmpty(s)==TRUE)
        printf("        ջ��!\n\n");   
    else
    {
        printf("          ջ����Ԫ������:\n\n");
        p=s->top;
        while(p>=0)
        {
            printf(" %d\n",s->data[p]);
            p--;

        }
        printf("\n\n");
    }
}
