#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define TRUE  1
#define FALSE  0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef char SElemType;

#define STACK_INIT_SIZE  100        //Initial size for memory allocation
#define STACKINCREMENT  10          //incremental size

typedef struct SqStack
{
	SElemType  *base;    //base pointer
	SElemType  *top;      //top pointer
	int        stacksize;    //current size
}SqStack;

//==================================================
// Initialize a stack
//====================================================
Status InitStack(SqStack *S)
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S->base) return ERROR;
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

//=================================
//Get the element at the top end
//==================================
Status GetTop(SqStack S, SElemType *e)
{
	if(S.top == S.base)	return ERROR;
	*e = *S.top;
	return OK; 
}

//==================================
//delete the element at the top end
//=====================================
Status Pop(SqStack *S, SElemType *e)
{
	if(S->base == S->top)	return ERROR;
	*e = *(S->top);
	S->top--;
	return OK;
}
//==================================
//Insert an element
//=================================
Status Push(SqStack *S, SElemType e)
{
	if(S->top - S->base >= S->stacksize)	return ERROR;
	*(++S->top) = e;
	return OK;
}

void main()
{
	char str[1024];
	int i;
	char e;
	SqStack S;
	InitStack(&S);
	printf("please input a string inlcuding (  )  [  ]  {  }\n");
	scanf("%s", str);
	   
	printf("the input string is %s\n", str);
	
	for (i = 0; str[i] != '\0'; i++)
	{
		Push(&S, str[i]);
		GetTop(S,&e);
		printf("the top element of the stack is %c\n",e);
	}
	
	for (i = 0; str[i] != '\0'; i++)
	{
		Pop(&S,&e);
		printf("the element of the stack pop is %c\n",e);
	}

}
