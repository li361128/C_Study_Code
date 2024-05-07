#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef char ElemType;
typedef int Status;

#define STACK_INIT_SIZE   100          // Initial size for memory allocation
#define STACKINCREMENT  10              // Incremental size

typedef struct {
    ElemType  *base;    // Base pointer
    ElemType  *top;     // Top pointer
    int        stacksize;     // Current size
} SqStack;

//========================================== 
// Initialization of array-based stack
//===========================================
Status InitStack(SqStack *S)
{
	S->base = (ElemType*)malloc(sizeof(SqStack));
	if(!S->base)	return ERROR;
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK; 
}

//========================================
// Test empty stack
//========================================
Status StackEmpty (SqStack S)
{
	return (S.base == S.top)?1:0;
}

//===============================================
// Get the length of a stack
//==============================================
int StackLength (SqStack S)
{
	return (S.top - S.base); 
}

//=====================================
// Get top item of a stack
//====================================
Status GetTop(SqStack S, ElemType *e)
{
	if(StackEmpty(S))	return ERROR;
	*e = *S.top;
	return OK;
}

//===================================================
// Delete an item from the stack
//====================================================
Status Pop(SqStack *S, ElemType *e)
{
	if(StackEmpty(*S))	return ERROR;
	*e = *--S->top;
	return OK;
}

//======================================
// Insert an item into the stack
//=======================================
Status Push(SqStack *S, ElemType e)
{
	if(S->top - S->base >= S->stacksize)
	{
		S->base = (ElemType*)realloc(S->base,(S->stacksize + STACKINCREMENT)*sizeof(ElemType));
		if(!S->base)	return ERROR;
		S->top = S->base + S->stacksize;
		S->stacksize +=  STACKINCREMENT;
	}
	*S->top++= e;
	return OK;
}

//======================================
// Print the elements in a stack
//=======================================
void PrintStack (SqStack S)
{
	int len = StackLength(S);
	int i = 0;
	for(;i < len;i ++)
	{
		ElemType e;
		Pop(&S,&e);
		printf("%d ",e);
	}
	printf("\n");
}

//======================================
// Compare two strings S and T containing backspaces
//=======================================
int CompareString(char *S,  char *T)
{
	SqStack stack_S,stack_T;
	InitStack(&stack_S);
	InitStack(&stack_T);
	int i;
	ElemType e;
	for(i = 0;S[i] != '\0';i ++)
	{
		if(S[i] !='#')	Push(&stack_S,S[i]);
		else
		{
			if(StackEmpty(stack_S)) continue;
			else Pop(&stack_S,&e);
		}
	}
	for(i = 0;T[i] != '\0';i ++)
	{
		if(T[i] !='#')	Push(&stack_T,T[i]);
		else
		{
			if(StackEmpty(stack_T)) continue;
			else Pop(&stack_T,&e);
		}
	}
	if(StackLength(stack_S) != StackLength(stack_T))	return FALSE;
	else
	{
		for(i = 0;i < StackLength(stack_S);i ++)
		{
			ElemType s_data,t_data;
			Pop(&stack_S,&s_data);
			Pop(&stack_T,&t_data);
			if(s_data != t_data)	return FALSE;
		}
	}
	return TRUE;
}

int main()
{
	char s[1000],t[1000];
	scanf("%s",&s);
	scanf("%s",&t);
	int res = CompareString(s,t);
	if(res)	printf("true");
	else printf("false");
	return 0;
}

