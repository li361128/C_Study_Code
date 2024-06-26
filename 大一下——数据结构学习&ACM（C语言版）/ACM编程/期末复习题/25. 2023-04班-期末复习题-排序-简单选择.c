#include <stdio.h>



int SelectMinKey(int A[], int i,int n) //A 为带排列的数组，i为待排的数，n为数组的长度

{ 

    //学生添加程序// 返回在A[i..n]中key最小的记录的序号
	int min = A[i], min_n = i;
	for(;i < n;i ++)
	{
		if(A[i] < min)
		{
			min = A[i];
			min_n = i;
		}
	}
	return min_n;

}



void SelectSort(int A[], int n)

{ 

   // 对A作简单选择排序。

   int i,j;

   int temp;

    for(i=0;i<n;i++)

    {

     //  选择第i小的记录，并交换到位

j=SelectMinKey(A, i, n); // 在A[i..n]中选择key最小的记录

if(i!=j) 

{

temp=A[i];

A[i]=A[j];

A[j]=temp; // 与第i个记录交换

}

}

}







int main()

{

int A[20];

int n;

int i;

scanf("%d",&n);

for(i=0;i<n;i++)

{

scanf("%d",&A[i]);

}

SelectSort(A,n);

printf("选择排序后:\n");

for (i = 0; i<n; i++)

{

printf("%d ", A[i]);

}

printf("\n");

return 1;

}



