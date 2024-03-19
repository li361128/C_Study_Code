#include "stdio.h"   

#include "stdlib.h"  

#define OK 1

#define ERROR 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;

typedef int ElemType;

typedef struct

{

    ElemType data[MAXSIZE];

    int length;

}SqList;


void ListTraverse(SqList L)

{
    int i;

    for(i=0;i<L.length;i++)

        printf("%d ",L.data[i]);

    printf("\n");

}

int ListLength(SqList L)

{

    return L.length;

}



Status GetElem(SqList L,int i,ElemType *e)

{

 /***补全函数***/
 	if(i < 1||i > L.length)	return ERROR;
	 *e = L.data[i - 1]; 
 	
	return OK;

}

Status ListInsert(SqList *L,int i,ElemType e)

{

    int k;
    
    if (L->length>=MAXSIZE || i<0 || i>L->length)

       return ERROR;

    for(k=L->length-1;k>=i;k--)
           L->data[k+1]=L->data[k];

    L->data[i]=e;

    L->length++;

    return OK;

}

void InterLeaving(SqList *L3, SqList L1, SqList L2)

{

 /***补全函数***/
 	int i = 1;
 	int e;
 	while (i <= L1.length ||i <= L2.length)
 	{
 		int tag = i;
 		if(i <= L1.length) 
		 {
		 	GetElem(L1,i,&e);
		 	ListInsert(L3,L3->length,e);
			 i ++;		 	
		  } 
		 if(i <= L2.length)
		 {
		 	if(tag == i) i--;
		 	GetElem(L2,i,&e);
		 	ListInsert(L3,L3->length,e);
			 i++;
		  } 
	 }

}

int main()

{

    SqList L1, L2, L3;

    Status i;

    int j,k,l;

//    printf("Please input the length of SqList1:\n");

    scanf("%d", &k);

    L1.length = 0;

    if (k > 0)

//        printf("Please input the element of SqList1 one by one:\n");

    for(j=1;j<=k;j++)

    {

        scanf("%d", &l);

        i=ListInsert(&L1,0,l);

    }

//    printf("The SqList1 is: ");

    ListTraverse(L1);

    printf("%d \n",ListLength(L1));

//    printf("Please input the length of SqList2:\n");

    scanf("%d", &k);

    L2.length = 0;

    if (k > 0)

//        printf("Please input the element of SqList2 one by one:\n");

    for(j=1;j<=k;j++)

    {

        scanf("%d", &l);

        i=ListInsert(&L2,0,l);

    }

//    printf("The SqList2 is: ");

    ListTraverse(L2);

    printf("%d \n",ListLength(L2));

    L3.length = 0;

    InterLeaving(&L3, L1, L2);

//    printf("The SqList3 of interleaving L1&2 is: ");

    ListTraverse(L3);

    printf("%d \n",ListLength(L3));

    return OK;

}
