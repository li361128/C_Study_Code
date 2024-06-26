#include <stdio.h>



int PartitionScore(int A[], int low, int high)

{
	int temp = A[low];
	while(low < high)
	{
		while(low < high && A[high] >= temp)	high--;
		A[low] = A[high];
		while(low < high && A[low] <= temp)		low++;
		A[high] = A[low];
	}
	A[low] = temp;
    return low;

}



void QSort(int A[], int low, int high)

{
	if(low < high)
	{
		int mid = PartitionScore(A, low, high);
		QSort(A, low, mid - 1);
		QSort(A, mid + 1, high);
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

QSort(A,0,n-1);

printf("¿ìËÙÅÅÐòºó:\n");

for (i = 0; i<n; i++)

{

printf("%d ", A[i]);

}

printf("\n");

return 1;

}
