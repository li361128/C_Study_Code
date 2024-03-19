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



// Create an empty list

Status InitList_Sq(SqList *L)

{

//学生添加
	L->elem = (int*)malloc(INIT_SIZE*sizeof(int));
	if (!L->elem) return OVERFLOW;
	L->length = 0;
	L->listsize = INIT_SIZE; 

}

//Create an array based list with n elements

Status CreateList_Sq(SqList *L, int a[], int n)

{

//学生添加
	int j = 0;
	for(;j < n;j ++)
	{
		L->elem[j] = a[j];
	}
	L->length = n;

}

//Get Element

Status GetElem(SqList L, int i, int *e)

{

//学生添加
	if(i < 1||i > L.length) return ERROR;
	*e = L.elem[i - 1];
	return OK;

}

//Insert

Status ListInsert(SqList *L, int i, int e)

{

//学生添加
	if(i < 1||i >L->length + 1) return ERROR;
	if(L->length == L->listsize) return ERROR;
	int j = L->length - 1;
	for(;j >= i - 1;j --)
	{
		L->elem[j + 1] = L->elem[j];
	}
	L->elem[i - 1] = e;
	L->length ++;
	return OK;

}



// Combine two sequential lists 



Status MergeList_Sq(SqList L1,SqList L2,SqList *L3)

{  

//学生添加
	int len1 = 0,len2 = 0,len3 = 0;
	while(L3->length < L1.length + L2.length)
	{
		if(len1 < L1.length &&( L1.elem[len1] <= L2.elem[len2]||len2 >= L2.length)) 
		{
			L3->elem[len3++] = L1.elem[len1++];
			L3->length++;
		}
		if(len2 < L2.length &&( L2.elem[len2] < L1.elem[len1]||len1 >= L1.length))
		{
			L3->elem[len3] = L2.elem[len2++];
			L3->length++;
		}
	}

}



//print out all elements

void PrintList_Sq(SqList L)

{ 

    //学生添加
	int j = 0;
	for(;j < L.length;j ++)
	{
		printf("%d ",L.elem[j]);
	}
    

}



int main()

{

int n1,n2,i,j;

int a[20],b[20];

SqList L1,L2,L3;


scanf("%d",&n1);

for(i=0;i<n1;i++){

scanf("%d",&a[i]);

}

scanf("%d",&n2);

for(i=0;i<n2;i++){

scanf("%d",&b[i]);

}


InitList_Sq(&L1);

InitList_Sq(&L2);

InitList_Sq(&L3);


CreateList_Sq(&L1,a,n1);

CreateList_Sq(&L2,b,n2);


MergeList_Sq(L1,L2,&L3);


PrintList_Sq(L3);


return 0;

}
