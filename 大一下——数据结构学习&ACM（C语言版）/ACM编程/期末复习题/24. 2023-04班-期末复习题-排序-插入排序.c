#include <stdio.h>

void MyInsertSort(int A[], int n)

{

//添加程序
	int i, j;
	for(i = 1; i < n;i ++)
	{
		if(A[i] > A[i + 1])
		{
			A[0] = A[i + 1];
			for(j = i;j > 0;j --)
			{
				if(A[j] > A[0])
					A[j + 1] = A[j];
				else
					break;				
			}
			A[j + 1] = A[0];
		}
	}

}

int main()

{

int A[20];

int n;

int i;

scanf("%d",&n);

for(i=1;i<=n;i++)

{

scanf("%d",&A[i]);

}

// 4 8 3 9 6 5 12 1 10 7



MyInsertSort(A,n);

printf("插入排序后:\n");

for (i = 1; i<=n; i++)

{

printf("%d ", A[i]);

}

printf("\n");

return 1;

}
