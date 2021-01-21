/*
#include<stdio.h>

int main()
{
	int i,j,m,n,max,maxj;  
	printf("请输入二维数组的：行 列\n");
	scanf("%d%d",&m,&n);
	int a[m][n];
	printf("请输入一个%d*%d的二维数组：\n",m,n);
	for(i=0;i<m;i++)
	    for(j=0;j<n;j++)
	        scanf("%d",&a[i][j]); 
	for(i=0;i<m;i++)
	{
		max=a[i][0];         //假设行元素第一个为本行最大值 
		maxj=0;              //行元素最大值的列下标 
		for(j=1;j<n;j++)     
		{
			if(max<a[i][j])
			{   
			    max=a[i][j];        //找出行最大 并标记最大值的列下标 
			    maxj=j;
             }
		}
		for(j=0;j<m;j++)
		{
			if(max>a[j][maxj])       
			    break;                 
		}
		if(j>=m)
		{		
			printf("二维数组的鞍点为：a[%d][%d]=%d\n",i,maxj,max);
			break;                
	     }                   
	}
	if(i>=m)
	    printf("此二维数组没有鞍点。\n");
	return 0;
}

*/


//总结：因为一个二维数组有且只有一个鞍点，所以可根据定义先找出行最大并标记列下标，
//再验证其值是所在列最小，若不满足提前break跳出，若满足则输出鞍点，并加break提前跳出循环防止鞍点是最后一行元素的情况 
//自然循环跳出和break跳出的循环变量的值不同作为一个判定条件 

#include <stdio.h>


int main()
{
    int i,j,m,n;  
	printf("请输入二维数组的：行 列\n");
	scanf("%d%d",&n,&m);
	int a[m][n];
	printf("请输入一个%d*%d的二维数组：\n",n,m);
	for(i=0;i<m;i++)
	    for(j=0;j<n;j++)
	        scanf("%d",&a[i][j]);        
    int max_p,min_l,maxj,mini;
    int ispoint=0,k;
    for (i=0;i<n;i++){
        max_p=a[i][0];
        maxj=0;                  
        for (j=0;j<m;j++){//找到第i行中最大的值
            if(a[i][j]>max_p){
                max_p=a[i][j];
                maxj=j;
            }
        }
        min_l=a[0][maxj];//该列号下的最小值
        mini=0;
        for (k=0;k<n;k++){
            if(min_l>a[k][maxj]){
                min_l=a[k][maxj];
                mini=k;//最小值的行号
            }
        }
        if(mini==i){
           printf("二维数组的鞍点为：a[%d][%d]=%d\n",mini,maxj,a[mini][maxj]); 
        }
    }
    if(ispoint)
        printf("此二维数组没有鞍点。\n");


    return 0;
}
