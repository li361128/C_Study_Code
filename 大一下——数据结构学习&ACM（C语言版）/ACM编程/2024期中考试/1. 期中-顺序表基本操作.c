#include <stdio.h>

#include <stdlib.h>

#define List_init_size 1000

typedef int Element;

typedef int Status;

#define OK 1

#define ERROR 0

#define TRUE 1

#define FALSE 0

 

typedef struct

{

    Element *elem;

    int length;

    int listsize;

} Sqlist;

 

//初始化顺序表Initialize sequence table

int Initlist(Sqlist *L)

{

    L->elem = (Element *)malloc(List_init_size * sizeof(Element));

    if (!L->elem) return ERROR;

    L->length = 0;

    L->listsize = List_init_size;

    return OK;

}

 

void Createlist(Sqlist *L, int m)

{

    int i;

    for (i = 0; i < m; i++)

    {

       scanf("%d", &L->elem[i]);

    }

    L->length = m;

}

 

int Listinsert(Sqlist *L, int k, int e)

{

    //将元素e插入到第k个元素之前Insert element e before the kth element

    if (k < 1 || k > L->length + 1)return ERROR;

    int j;

    int pos = k;

 

    for (j = L->length - 1; j >= pos - 1; j--)

    {

       L->elem[j + 1] = L->elem[j];

    }

    L->elem[pos - 1] = e;

    L->length++;

    return OK;

 

}

 

//取顺序表的第i个元素Get the i-th element of the sequencial list

Status GetElem(Sqlist L,int i, int *e)

{

   if(i<1 || i>L.length)

      return ERROR;

    *e=L.elem[i-1];

    return OK;

}

 

//判断在顺序表中是否存在某元素（存在返回值TRUE；不存在返回值FALSE）

//Determine whether an element exists in the sequencial list (return value TRUE exists; return value FALSE does not exist)

Status isPresent(Sqlist L, int e){

 

//★★★请补全代码Please complete the code
	int i = 0;
	for(;i < L.length;i ++)
	{
		if(L.elem[i] == e)	return TRUE;
	} 
	return FALSE;
   

}

 

void ComplemSet (Sqlist L1, Sqlist L2, Sqlist *L3)

{

//★★★请补全代码Please complete the code
	int i = 0,k = 1;
	for(;i < L1.length && i < L2.length;i ++)
	{
		if(!isPresent(L2,L1.elem[i]))
		{
			Listinsert(L3,k,L1.elem[i]);
			k++;
		}
	}

}

 

void Display(Sqlist L)

{

//★★★请补全代码Please complete the code
	int i = 0;
	for(;i < L.length;i ++)
	{
		printf("%d ",L.elem[i]);
	}
	printf("\n");

   

}

 

int main()

{

    int m, n;

    Sqlist A, B, C;

    printf("Please enter the number of elements in List A and List B in sequence: \n");

    scanf("%d%d", &m, &n);

    Initlist(&A);

    Initlist(&B);

    Initlist(&C);

    printf("Please enter the elements in List A in sequence: \n");

    Createlist(&A, m);

    printf("Please enter the elements in List B in sequence: \n");

    Createlist(&B, n);

    ComplemSet (A, B, &C);

    printf("The elements of List C are: \n");

    Display(C);

    return 0;

}
