#include <malloc.h>

#include <stdio.h>

#include <stdlib.h>

#define TRUE  1

#define FALSE  0

#define OK 1

#define ERROR 0

#define OVERFLOW -2

typedef int Status;

#define INIT_SIZE 100

#define LISTINCREMENT 10  

typedef int ElemType;



typedef struct

{

    ElemType *elem;

    int length;

    int listsize;

}SqList;



// Initialize an empty list

Status InitList_Sq(SqList *L)

{

 //学生添加
 	L->elem = (int*)malloc(INIT_SIZE * sizeof(int));
 	L->length = 0;
 	L->listsize = INIT_SIZE;
}



//Create an array based list with n elements

Status CreateList_Sq(SqList *L, int a[], int n)

{

 //学生添加
	int i = 0;
	for(;i < n;i ++)
	{
		L->elem[i] = a[i]; 
	}
	L->length = n;
}

// Delete the ith elements of sequential list L



Status DeleteList_Sq(SqList *L, int m,int k)

{    

 //学生添加
 	int i = 0;
 	
 	for(;m < L->length - k;m ++)
 	{
 		L->elem[m] = L->elem[m + k];
	 }
	 L->length -=k;
}



//print out all elements

void PrintList_Sq(SqList L)

{ 

 //学生添加
	 int i = 0;
	 for(;i < L.length;i ++)
	 {
	 	printf("%d ",L.elem[i]); 
	 }
}

int main()

{ 
	int n;
	scanf("%d",&n);
	int i,arr[n];
	for(i = 0;i < n;i ++)
	{
		scanf("%d",&arr[i]);
	 } 
	 SqList sq;
	 InitList_Sq(&sq);
	 
	 CreateList_Sq(&sq,arr,n);
	 
	 int m,k;
	 
	 scanf("%d%d",&m,&k);
	 
	 DeleteList_Sq(&sq,m,k);
	 
	 PrintList_Sq(sq);
	 
	 return 0;

    //学生添加



}
