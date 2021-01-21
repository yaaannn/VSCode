#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100
typedef struct
{
	int r[MAXSIZE + 1];
	int length;
} Sqlist;

void BubbleSort(Sqlist *S) /*简单冒泡排序*/
{
	int i, j;
	for (i = 1; i < S->length; i++)
	{
		for (j = i + 1; j <= S->length; j++)
		{
			if (S->r[i] > S->r[j])
			{
				int temp;
				temp = S->r[i];
				S->r[i] = S->r[j];
				S->r[j] = temp;
			}
		}
	}
}

void StraightInsertSort(Sqlist *S) /*插入排序*/
{
	int i, j;
	for (i = 2; i <= S->length; i++)
	{
		if (S->r[i] < S->r[i - 1])
		{
			S->r[0] = S->r[i];
			for (j = i - 1; S->r[j] > S->r[0]; j--)
				S->r[j + 1] = S->r[j];
			S->r[j + 1] = S->r[0];
		}
	}
}

void ShellSort(Sqlist *S) /*希尔排序*/
{
	int i, j, k = 0;
	int increment = S->length;
	while (increment > 1)
	{
		increment = increment / 3 + 1;
		for (i = increment + 1; i <= S->length; i++)
		{
			if (S->r[i] < S->r[i - increment])
			{
				S->r[0] = S->r[i];
				for (j = i - increment; j > 0 && S->r[0] < S->r[j]; j -= increment)
					S->r[j + increment] = S->r[j];
				S->r[j + increment] = S->r[0];
			}
		}
	}
}

/*快速排序*/
int Partition(Sqlist *S, int low, int high)
{
	int pivotkey;
	int temp;
	pivotkey = S->r[low]; 
	while (low < high)	  
	{
		while (low < high && S->r[high] >= pivotkey)
			high--;
		temp = S->r[low];
		S->r[low] = S->r[high];
		S->r[high] = temp;
		while (low < high && S->r[low] <= pivotkey)
			low++;
		temp = S->r[low];
		S->r[low] = S->r[high];
		S->r[high] = temp;
	}
	return low; 
}

void QSort(Sqlist *S, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(S, low, high); 
		QSort(S, low, pivot - 1);		 
		QSort(S, pivot + 1, high);		 
	}
}

void QuickSort(Sqlist *S)
{
	QSort(S, 1, S->length);
}

int Binary_Search(Sqlist S, int n, int key)/*折半查找*/
{
	int low, high, mid;
	low = 1;
	high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < S.r[mid])		 
			high = mid - 1;		 
		else if (key > S.r[mid]) 
			low = mid + 1;		 
		else
			return mid;
	}
	return 0;
}

int Sequential_Search(Sqlist S, int n, int key)/*顺序查找*/
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (S.r[i] == key)
			return i;
	}
	return 0;
}

void print(Sqlist s0)/*打印序列*/
{
	for (int i = 0; i < s0.length; i++)
	{
		printf(" %d", s0.r[i + 1]);
	}
	printf("\n");
}

int main()
{
	srand(time(0));
	int a[30];
	int i;
	int result;
	int key;
	Sqlist s0;
	for (i = 0; i < 30; i++)
	{
		a[i] = rand() % 90 + 10; //随机生成30个两位整数存放在数组a中
	}
	for (i = 0; i < 30; i++)
	{
		s0.r[i + 1] = a[i];
	}
	s0.length = 30;
	printf("原序列为:");
	print(s0);
	printf("冒泡排序:");
	BubbleSort(&s0);
	print(s0);
	printf("请输入你要查找的数据:");
	scanf("%d", &key);
	result = Sequential_Search(s0, 30, key);
	printf("顺序查找:%d \n", result);
	result = Binary_Search(s0, 30, key);
	printf("折半查找:%d \n", result);
	printf("插入排序:");
	StraightInsertSort(&s0);
	print(s0);
	printf("快速排序:");
	QuickSort(&s0);
	print(s0);
	printf("希尔排序:");
	ShellSort(&s0);
	print(s0);
}