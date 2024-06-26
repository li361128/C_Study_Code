#include <stdio.h>
 
//冒泡排序
void bubbleSort(int arr[], int n) 
{
//★★★请补全代码
	int i, j;
	for(i = 0 ;i < n - 1; i ++)
	 {
	 	for(j = 0 ;j < n - i - 1;j ++)
	 	{
	 		if(arr[j] < arr[j + 1])
			 {
			 	int temp = arr[j];
			 	arr[j] = arr[j +1];
				 arr[j + 1] = temp; 
			  } 
		 }
	 }
    
}
 
//简单选择排序
void selectionSort(int arr[], int n) 
{
//★★★请补全代码
	int i ,j;
	for(i = 0; i < n;i ++)
	{
		int min = arr[i],min_n = i;
		for(j = i ; j < n;j ++)
		{
			if(arr[j] < min)
			{
				min = arr[j];
				min_n = j;
			}
		}
		if(min_n != i)
		{
			arr[min_n] = arr[i];
			arr[i] = min;
		}
	}
    
}

//打印数组 
void printfArray(int arr[], int n) {
    bubbleSort(arr, n);
    printf("Array by bubbleSort are: ");
    int i;
    for(i=0; i< n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    selectionSort(arr, n);
    printf("Array by selectionSort are: ");
    for(i=0; i< n;i++){
        printf("%d ", arr[i]);
    }       
    printf("\n");
       
}
 
 
int main() {
    int arr[100];
    int n, k, i;
    scanf("%d", &n);
 
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
 
    printfArray(arr, n);
 
    return 0;
}
