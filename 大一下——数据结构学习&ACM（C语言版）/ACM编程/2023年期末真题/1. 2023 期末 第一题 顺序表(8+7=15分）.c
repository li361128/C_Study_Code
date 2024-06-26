#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 100 //顺序表可能达到的最大长度

typedef int Status; //Status是函数返回值类型，其值是函数结果状态代码
typedef int ElemType; //ElemType为可定义的数据类型，此处设为int类型

typedef struct
{
    ElemType *elem; //存储空间的基地址
    int length; //线性表当前长度
}SqList;

//顺序表的初始化（构造一个空的顺序表L） 
Status InitList_Sq(SqList *L)
{
    L->elem=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE); //为顺序表分配一个大小为MAXSIZE的数组空间
    if(!L->elem)
        return ERROR; //存储分配失败
    L->length=0; //空表长度置为0
    return OK;
}

//创建长度为n的顺序表
Status CreateList_Sq(SqList *L, int n)
{
    if(n<=0||n>MAXSIZE)
        return ERROR;
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &L->elem[i]);
    }
    L->length=n;
    return OK;
}

//删除线性表L中所有在[a,b]范围内的数据元素，其中a,b均为整数，且a<b
//要求算法时间复杂度为O(n)且空间复杂度为O(1)
Status DeleteItem(SqList *L,int a,int b)
{
    //请补全代码
    if(a >= b)	
	{
		printf("SqList delete range error.");
		return ERROR;
	} 
	int i = 0, k = 0;

	for(i = 0;i < L->length;i ++)
	{
		if(L->elem[i] >b || L->elem[i] < a)
		{
			L->elem[k ++] = L->elem[i];
		}
	}
	L->length = k;
	return OK;
	 


}

//输出顺序表L中的全部元素 
void PrintList_Sq(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}


int main()
{
//请补全代码
	int n;
	scanf("%d",&n);
	if(n <= 0 || n > MAXSIZE)
	{
		printf("SqList length error.");
		return ERROR;
	}
	SqList L;
	InitList_Sq(&L);
	CreateList_Sq(&L, n);
	
	int a, b;
	scanf("%d %d",&a, &b);
	if(DeleteItem(&L, a, b) == OK)
		PrintList_Sq(L);
	
	return 0;
}
