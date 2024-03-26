#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int SElemType;  
typedef int Status;

typedef struct L_node {
    SElemType data;  //data field
    struct L_node *next;   //pointer field
} LNode, *LinkList;

typedef struct {
    LinkList Head;  //head pointer
    int length;  //length
} LinkStack;

//========================================== 
// initialization of linked list based stack
//=========================================== 
Status InitStack(LinkStack *S)
{
   S->Head = (LinkList)malloc(sizeof(LNode));
   if(!S->Head)	return ERROR;
   S->Head->next = NULL;
   S->length = 0;
   return OK; 
}

//========================================
// Test empty stack
//========================================
Status StackEmpty(LinkStack S)
{
	return (!S.length);
}

//===============================================
// Get the length of a stack
//==============================================
int StackLength(LinkStack S)
{
	return S.length;
}

//=====================================
// Get top item of a stack
//====================================
Status GetTop(LinkStack S, SElemType *e)
{
	if(StackEmpty(S))	return ERROR;
	*e = S.Head->next->data;
}

//===================================================
// Delete an item from the stack
//====================================================
Status Pop(LinkStack *S, SElemType *e)
{
	if(StackEmpty(*S))	return ERROR;
	LinkList p = S->Head;
	LinkList r = p->next;
	p->next = r->next;
	*e = r->data;
	free(r);
	S->length --;
	return OK;
}

//======================================
// Insert an item into the stack
//=======================================
Status Push(LinkStack *S, SElemType e)
{
	LinkList p = S->Head;
	LinkList r;
	r = (LinkList)malloc(sizeof(LNode));
	r->data = e;
	r->next = p->next;
	p->next = r;
	S->length ++;
	return OK;
}

//======================================
// Print the elements in a stack
//=======================================
void PrintStack(LinkStack S)
{
	LinkList p = S.Head->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	 } 
	 printf("\n");
}

//======================================
// 删除堆栈中值为x的元素（可能有多个），返回堆栈的长度
//=======================================
int DeleteElem(LinkStack *S, SElemType x)
{
	LinkList p = S->Head;
	while(p->next)
	{
		if(p->next->data != x)	p = p->next;
		else
		{
			LinkList r = p->next;
			p->next = r->next;
			free(r);
			 S->length --;
		  }  
	}
	return S->length;
}

int main()  
{  
	LinkStack S;
	InitStack(&S);
	int n,i = 0;
	scanf("%d",&n);
	int arr[n];
	for(;i < n;i ++)	
	{
		scanf("%d",&arr[i]);
		Push(&S,arr[i]);
	}
	int x;
	scanf("%d",&x);
	
	int tag = DeleteElem(&S,x);
	PrintStack(S);
	printf("%d",tag);
}

