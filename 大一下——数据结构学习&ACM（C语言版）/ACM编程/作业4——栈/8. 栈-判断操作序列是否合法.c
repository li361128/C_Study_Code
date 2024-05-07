#include <stdio.h>  

#include <stdlib.h>  

#include <malloc.h>

 

#define ERROR 0

#define OK 1

#define TRUE 1

#define FALSE 0

typedef char SElemType;  

typedef int Status;

 

// definition of array based stack

#define STACK_INIT_SIZE   100          //Initial size for memory allocation

#define STACKINCREMENT  10          //incremental size

typedef struct{

   SElemType  *base;    //base pointer

   SElemType  *top;      //top pointer

   int        stacksize;     //current size

}SqStack;

 

//========================================== 

// initialization of array-based stack

//=========================================== 

Status InitStack(SqStack *S)
{

	S->base = (char*)malloc(STACK_INIT_SIZE*sizeof(char));
	if(!S->base)	return ERROR;
	S->top = S->base;
	S->stacksize =  STACK_INIT_SIZE;
	return OK;
}

 

//========================================

//Test empty stack

//========================================

Status StackEmpty (SqStack S)
{

	return (S.base == S.top)?TRUE:FALSE;

}

 

//===============================================

// Get the length of a stack

//==============================================

int StackLength (SqStack S)
{

	return S.top - S.base;                            

}

 

//=====================================

// Get top item of a stack

//====================================

Status GetTop(SqStack S, SElemType *e)
{
	if(StackEmpty(S))	return ERROR;
	*e = *(S.top - 1);
 	return OK;

}

 

//===================================================

// Delete an item from the stack

//====================================================

Status Pop(SqStack *S)
{

	if(StackEmpty(*S))	return ERROR;
	--S->top; 
	return OK;
}

 

//======================================

// Insert an item into the stack

//=======================================

Status Push(SqStack *S,SElemType e)
{

	if(S->stacksize == StackLength(*S)) 
	{
		S->base = (char*)realloc(S->base,(S->stacksize + STACKINCREMENT) *sizeof(char));
		if(!S->base)	return ERROR;
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT; 
	 } 
	 *S->top ++ = e;
	return OK;
}

 

//======================================

// Print the elements in a stack

//=======================================

void PrintStack (SqStack S)
{
	
	SElemType *p = S.base;
	while(p < S.top)
	{
		printf("%c",*p++);
	}
	printf("\n"); 
}

 

//======================================

// 检查操作序列是否合法, 如果合法，返回1，否则返回0

//=======================================

int isLegal(char *s)

{
	SqStack T; 
	InitStack(&T);
	
	int i = 0;
	for(;s[i] != '\0';i ++)
	{
		if(s[i] == 'I')	Push(&T,s[i]);
		else if(s[i] == 'O')	if(!Pop(&T)) return ERROR;
	}
	return StackEmpty(T);
}



int main( )  

{  
	char str[10010];
	scanf("%s",str);
	int tag = isLegal(str);
	if(tag)	printf("True");
	else printf("False");
	return OK;


 } 
