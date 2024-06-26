#include<stdio.h>
int BinSearch(int arr[],int key,int low, int high)                          //折半查找法（二分法）
{
	if(low > high)	
		return -1;
	
	int mid = (low + high) / 2;
	if(arr[mid] == key)	
		return mid;
		
	else if(arr[mid] > key)	
		return BinSearch(arr, key, low, mid - 1);
	else
		return BinSearch(arr, key, low + 1, high);
		
//	else if(arr[mid] > key)	
//		return BinSearch(arr, key, low, mid - 1) > 0 ? BinSearch(arr, key, low, mid - 1) : -1;
//	else
//		return BinSearch(arr, key, low + 1, high) > 0 ? BinSearch(arr, key, low + 1, high) : -1;

}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10,11};                   
	printf("%d\n",BinSearch(arr,7,1,(sizeof(arr)/sizeof(arr[0]))));
	return 0;
}
