#include <stdio.h>
//===========================================
// Get the Max Data in A[] in recursive manner
//============================================
int GetMax_R(int A[], int n)
{
	if(n <= 0)	return 0; 
	else if(n == 1 || A[n - 1] > GetMax_R(A, n - 1))	return A[n - 1];
	else return GetMax_R(A, n - 1);
}

int main()
{
	int A[] = { 1,8,6,-4,3,9,10,12,56,45,23 };
	int max;
	
	max = GetMax_R(A, sizeof(A)/sizeof(A[0]));
	
	printf("the max of array A is : %d\n", max);
	
	return 0;

}
