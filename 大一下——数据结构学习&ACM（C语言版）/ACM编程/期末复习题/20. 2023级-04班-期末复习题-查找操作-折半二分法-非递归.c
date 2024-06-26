/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "stdio.h"

#include "stdlib.h"

typedef struct{

   int  Age[16];  // 数据元素存储空间基址

   int  length;   // 表长度

}SSTable;

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */



//补充函数

int Search (SSTable ST, int key)
{
    //学生增加的程序~
    int left = 0, right = ST.length;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		printf("%d",ST.Age[mid + 1]);
		if(ST.Age[mid + 1] > key)	right = mid - 1;
		else if(ST.Age[mid + 1] == key)	
			return mid + 1;
		else left = mid + 1;
	 } 
	 return 0;
}



/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

int main()

{

	SSTable ST;
	
	ST.length=15;
	
	ST.Age[0]=ST.length;

   int a[15]={5,10,11,15,17,19,21,25,36,38,50,51,55,57,68};
	
	int i, val, ret;

   for(i=0; i<15; i++)

	{
	
		ST.Age[i+1]=a[i];
	
        printf("%d", ST.Age[i+1]);
	
	}

   printf("\n请输人所要查找的元素：");

   scanf("%d",&val);
	
	printf("\n");

   ret = Search(ST,val);

   if(0 == ret)

       printf("\n查找失败\n");

   else

       printf("\n查找成功\n");

return 0;

}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
