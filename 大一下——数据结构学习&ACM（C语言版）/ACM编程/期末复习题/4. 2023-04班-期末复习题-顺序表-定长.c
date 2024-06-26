//±àÐ´FindElementº¯Êý

#include <stdio.h>


//============================================================
//
// Find an element is an array.
// the total number to elements is stored in A[0]
//
// If the element is found, return i( 1<i<n ), otherwise return 0
//============================================================


int FindElement(int A[], int n, int x)
{
	int i = 0;
	for(i = 1; i <= n ;i ++)
	{
		if(A[i] == x)	return i;
	 } 
	 return 0;
}

int main()
{
	int A[] = {9, 1, 3, 5, 8, 9, 5, 7, 10, 12 }; //A[0] stores the total number of elements
	int e;
	int RetVal;
	
	
	scanf("%d", &e);
	RetVal=FindElement(A, A[0], e);
	
	if(RetVal)
		printf("The position of the element is %d\n", RetVal);
	else
		printf("The element doesn't exist in the array!\n");
		
	return 0;
}
