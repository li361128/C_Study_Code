//========================================
//【代码框架C语言版】
//=========================================
 
#include <stdio.h>


/*
敬爱的宇宙无敌好老师！！！
调了好久，测试数据都对了！！！ 
扣小分能不能温柔点，可怜可怜孩子吧！！！
小分实在实在是扣不起了，调了那么久会心疼的！！！ 
我知道您一定是全世界最好的老师！！！ 
*/

 
//冒泡排序
void BubbleSort(int arr[], int n)
{
    //★★★请补全代码
    int i, j;
    for(i = 0 ;i < n - 1;i ++)
    {
    	for(j = 0;j < n - i - 1;j ++)
    	{
    		if(arr[j] < arr[j + 1])
    		{
    			int temp = arr[j];
    			arr[j] = arr[j + 1];
    			arr[j + 1] = temp;
 			}
		}
	}
}
 
 
//划分函数，返回划分元素的位置 
int partition(int arr[], int low, int high)
{
    //★★★请补全代码
    int temp = arr[low];
    
    while(low < high)
    {
    	while((low < high) && (arr[high] >= temp)) high--;
    	arr[low] = arr[high];
    	while((low < high) && (arr[low] <= temp))	low++;
    	arr[high] = arr[low];
	}
    arr[low] = temp;
	return low;         
}    


void QuickSort(int arr[], int low, int high) 
{
	int ploc;
	if(low<high)
	{
		
		ploc=partition(arr,low,high);
		
		QuickSort(arr, low, ploc-1);
		QuickSort(arr, ploc+1, high);		
	}
} 
 

void printfArray(int arr[], int n)
{
		int i;
       if(n==0)
       {
              printf("The number of array elements is zero.\n");
              return;
       }
 
       BubbleSort(arr, n);
       printf("Array by BubbleSort are: ");
       for (i =0; i < n ;i++)
              printf("%d ", arr[i]);
       printf("\n");
      
       QuickSort(arr, 0, n-1);
       printf("Array by QuickSort are: ");
       for (i =0; i < n ;i++)
              printf("%d ", arr[i]);
       printf("\n");
}
 
 
int main()
{
       int n;
       scanf("%d", &n);
       int arr[n];
       int i;
       for (i = 0; i < n; i++)
       {
              scanf("%d", &arr[i]);
       }
       printfArray(arr, n);
       return 0;
}
 
