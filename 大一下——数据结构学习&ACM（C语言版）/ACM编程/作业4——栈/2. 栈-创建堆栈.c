#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;

#define STACK_INIT_SIZE   100     //Initial size for memory allocation
#define STACKINCREMENT  10        //Incremental size

typedef struct{
   SElemType *base;    //Base pointer
   SElemType *top;     //Top pointer
   int stacksize;       //Current size
} SqStack;

Status InitStack(SqStack *S)
{
	S->base = (SElemType *)malloc(sizeof(SElemType));
	if(!S->base) return ERROR;
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE ;
	return OK;
}

Status StackEmpty(SqStack S)
{
	return (S.top == S.base)?TRUE :FALSE;
}

int StackLength(SqStack S)
{
	return (S.top - S.base);
}

Status GetTop(SqStack S, SElemType *e)
{
	if(StackEmpty(S))	return ERROR;
	*e = *--S.top;
	return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
	if(StackEmpty(*S))	return ERROR;
	*e = *(--S->top);
}

Status Push(SqStack *S, SElemType e)
{
	if(S->top - S->base == S->stacksize)	return ERROR;
	*S->top++ = e;
	return OK;
}

void PrintStack(SqStack S)
{
	int i = 0,e;
	int len = StackLength(S);
	for(;i < len;i ++)
	{
		Pop(&S,&e); 
		printf("%d ",e);
	}
	printf("\n");
}

int reverseOutput(SqStack S)
{
	if(StackEmpty(S))	return ERROR;
	PrintStack(S);
	return StackLength(S);
}

int main()
{
	SqStack S;
	InitStack(&S);
	int n,i = 0;
	scanf("%d",&n);
	int arr[n];
	for(;i < n;i ++)	
	{
		scanf("%d",&arr[i]); 
		Push(&S,arr[i]);
	}
	printf("%d",reverseOutput(S));
	return OK;
}

