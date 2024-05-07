#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void PrintMax(int a[],int len)
{
	int k,max=a[0],index=0;
	for(k=0;k<len;k++)
	{
		if(a[k]>max)
		{
			max=a[k];
			index=k;
		}
	}
	printf("%d %d ",max,index);
	for(k=0;k<len;k++)
	{
		if(a[k]!=max&&a[k]*2>max)
		{
			printf("NO");
			return ;
		}
	}
	printf("YES");
}

int main(int argc, char *argv[]) 
{
	int len;
	scanf("%d",&len);
	int arr[len];
	int i;
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	}
	PrintMax(arr,len); 
	 
	return 0;
}
