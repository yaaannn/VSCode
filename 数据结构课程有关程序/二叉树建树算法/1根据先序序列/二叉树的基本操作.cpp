#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 100
#define NLAYER  4

typedef struct BiTNode               // ����������ڵ�ṹ
{
	char data;                       // ������
    struct BiTNode *LChild,*RChild;  // ���Һ���ָ����
}BiTNode,*BiTree;
BiTree T;

//(1) ����������
void CreateBiTree(BiTree *bt)
{ // �����������н����������Ķ�������Ĺ���
	char ch;
    scanf("%c",&ch);  
    if(ch=='#') *bt=NULL;
    else 
	{
		*bt=(BiTree)malloc(sizeof(BiTNode)); // ����һ���½��
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->LChild));      // ����������
        CreateBiTree(&((*bt)->RChild));      // ����������
	}
}

//(2) ���ʹ�ӡ������
void TranslevelPrint(BiTree bt)
{  //���㷨ʵ�ֶ������İ����ӡ
	struct node
	{
		BiTree vec[MAXLEN];           // ��������
		int layer[MAXLEN];            // ������ڵĲ�
		int locate[MAXLEN];           // ��ӡ����λ��
		int front,rear;
	}q;                               // �������q
	int i,j,k;
	int nLocate;
	j = 1;
	k = 0;
	q.front = 0;                      // ��ʼ������q��ͷ����β
	q.rear = 0;
    printf(" ");
	q.vec[q.rear] = bt;               // �����������ڵ������
	q.layer[q.rear] = 1;
	q.locate[q.rear] = 20;
	q.rear = q.rear + 1;
	while(q.front < q.rear)
	{
		bt = q.vec[q.front];
		i = q.layer[q.front];        
		nLocate = q.locate[q.front];
		if(j < i)                      // �����ӡʱ����
		{
			printf("\n");
			printf("\n");
			j = j + 1;			
			k = 0;
			while(k < nLocate)
			{
				printf(" ");
				k++;
			}
		}
		while(k < (nLocate-1))          // ���ý����ȿ��ƺ���λ��
		{
			printf(" ");
			k++;
		}
		printf("%c",bt->data);
		q.front = q.front + 1;
		if(bt->LChild != NULL)          // �����������������������ڵ������
		{		
			q.vec[q.rear] = bt->LChild;
			q.layer[q.rear] = i + 1;
			q.locate[q.rear] =(int)(nLocate - pow(2, NLAYER-i-1));
			q.rear = q.rear +1;
		}
		if(bt->RChild != NULL)         // �����������������������ڵ������
		{		
			q.vec[q.rear] = bt->RChild;
			q.layer[q.rear] = i + 1;
			q.locate[q.rear] =(int)(nLocate + pow(2, NLAYER-i-1));
			q.rear = q.rear +1;
		}
	}
}

//(3) ������
void Visit(char ch)
{
	printf("%c  ",ch);
}

//(4) �������������
void  PreOrder(BiTree root) 
{// �������������, rootΪָ�������(��ĳһ����)������ָ��
	if (root!=NULL)
	{
		Visit(root ->data);       // ���ʸ����
		PreOrder(root ->LChild);  // �������������
		PreOrder(root ->RChild);  // �������������
	}
}

//(5) �������������
void  InOrder(BiTree root)  
{// �������������, rootΪָ�������(��ĳһ����)������ָ��
	if (root!=NULL)
	{
		InOrder(root ->LChild);    // �������������
		Visit(root ->data);        // ���ʸ����
		InOrder(root ->RChild);    // �������������
	}
}

//(6) �������������
void  PostOrder(BiTree root)  
{//���������������rootΪָ�������(��ĳһ����)������ָ��
	if(root!=NULL)
	{
		PostOrder(root ->LChild);  // �������������
		PostOrder(root ->RChild);  // �������������
		Visit(root ->data);        // ���ʸ����
	}
}

//(7) ���Ҷ�ӽ��
void  PreOrderLeaf(BiTree root) 
{//������������������Ҷ�ӽ��, rootΪָ�������������ָ��
	if (root!=NULL)
	{
		if (root ->LChild==NULL && root ->RChild==NULL)
			printf("%c  ",root ->data);   // ���Ҷ�ӽ��
		PreOrderLeaf(root ->LChild);      // �������������
		PreOrderLeaf(root ->RChild);      // �������������
	}
}

//(8) ���Ҷ�ӽ��ĸ���
int LeafCount(BiTree root)
{
	int LeafNum;
	if(root==NULL)	
		LeafNum=0;
	else 
		if((root->LChild==NULL)&&(root->RChild==NULL))
			LeafNum=1;
		else 
			LeafNum=LeafCount(root->LChild)+LeafCount(root->RChild);	// Ҷ����Ϊ����������Ҷ����Ŀ֮��
 
	return LeafNum;
}

//(9) ��������������
int PostTreeDepth(BiTree root)   // ������������������ȵݹ��㷨 
{
	int hl,hr,max;
	if(root!=NULL)
	{
		hl=PostTreeDepth(root->LChild);  // �������������
		hr=PostTreeDepth(root->RChild);  // ������������� 
		max=hl>hr?hl:hr;                 // �õ�����������Ƚϴ���
		return(max+1);                   // ����������� 
	}
	else return(0);                      // ����ǿ������򷵻�0 
}

//(10) ��Ҫ�����������������û�����
void mainwork()
{
	int yourchoice;
      
	printf("\n------------------------��ӭʹ�ö�����������������---------------------------\n");
	printf("\n                               �� �� ѡ ��                                 \n\n");
	printf("        1. ��״���������                        2. �������������             \n");
	printf("        3. �������������                        4. �������������             \n");
	printf("        5. ���Ҷ�ӽ��                          6. ���Ҷ�ӽ�����           \n");
	printf("        7. ��������������                      8. �˳�                       \n");
	printf("\n-----------------------------------------------------------------------------\n");
    printf("���������ѡ��");
	scanf("%d",&yourchoice);
	while(!(yourchoice==1||yourchoice==2||yourchoice==3||yourchoice==4||yourchoice==5||yourchoice==6
		  ||yourchoice==7||yourchoice==8))
	{
		printf("����ѡ����ȷ��������\n");
		scanf("%d",&yourchoice);
	}
	while(1)
	{
		switch(yourchoice)
		{
			case 1:	printf("������״Ϊ:\n");TranslevelPrint(T);  getch();		break;
			case 2:	printf("�����������Ϊ:"); PreOrder(T);	break;
			case 3:	printf("\n�����������Ϊ:");InOrder(T); break;
			case 4:	printf("\n�����������Ϊ:");PostOrder(T);	break;
			case 5:	printf("Ҷ�ӽ��Ϊ:"); PreOrderLeaf(T); 	break;
			case 6:	printf("Ҷ�ӽ�����Ϊ:%d",LeafCount(T));	        break;
		    case 7: printf("�����������Ϊ:%d",PostTreeDepth(T));   break;
			case 8: system("cls");	exit(0); 			break;
			default:  break;
		}
	
	    	printf("\n------------------------��ӭʹ�ö�����������������---------------------------\n");
	        printf("\n                               �� �� ѡ ��                                 \n\n");
	        printf("        1. ��״���������                        2. �������������             \n");
	        printf("        3. �������������                        4. �������������             \n");
	        printf("        5. ���Ҷ�ӽ��                          6. ���Ҷ�ӽ�����           \n");
	        printf("        7. ��������������                      8. �˳�                       \n");
	        printf("\n-----------------------------------------------------------------------------\n");

	    printf("\n���������ѡ��");
	    scanf("%d",&yourchoice);
	}//endwhile(1)

}//mainwork

//(11) �����������������������ù�����ģ�麯��
int main()
{
	    
	    printf("����������������Ľ�����У�\n");
		CreateBiTree(&T);
        printf("�밴�˵���ʾ������\n");
        mainwork();
	
}
