#include <stdio.h>
//===============================
// Calculate the sum of array in recursive way
//===============================
int GetSum_R(int a[], int n)
{
	if(n == 0)	return 0;
	return a[n - 1] + GetSum_R(a, n - 1); 
}
int main()
{
	int A[] = {1,2,3,4,5,6,7,8,9,10};
	int sum;
	
	sum = GetSum_R(A, sizeof(A)/sizeof(int));
	
	printf("the sum of array A: %d\n", sum);
	return 0;
}


