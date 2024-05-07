#include <stdio.h>  

#include <stdlib.h>  

#include <malloc.h>

 

#define ERROR 0

#define OK 1

#define TRUE 1

#define FALSE 0

 

typedef int SElemType;  

typedef int Status;

 

typedef struct L_node{

     SElemType     data;  //data field

     struct L_node  *next;   //pointer field

}LNode, *LinkList;

 

typedef struct{

   LinkList  Head;  //head pointer

   int  length;  //length

}LinkStack;

 

//========================================== 

// initialization of linked list based stack

//=========================================== 

Status InitStack(LinkStack *S)
{
	
	S->Head = (LinkList)malloc(sizeof(LNode));
	if(!(S->Head))	return ERROR; 
	S->Head->next = NULL;
	S->length = 0;
	return OK;
}

 

//========================================

//Test empty stack

//========================================

Status StackEmpty (LinkStack S)
{

	return (S.length == 0)?TRUE:FALSE;

}

 

//===============================================

// Get the length of a stack

//==============================================

int StackLength (LinkStack S)
{
 	               

}

 

//=====================================

// Get top item of a stack

//====================================

int GetTop(LinkStack S)
{
	if(S.length == 0) return ERROR;
	return S.Head->next->data;

}

 

//===================================================

// Delete an item from the stack

//====================================================

Status Pop(LinkStack *S, SElemType *e)
{
	if(S->length == 0)	return ERROR;
	LinkList p = S->Head->next;
	LinkList r = S->Head;
	*e = p->data;
	r->next = p->next;
	S->length --;
	free(p);
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
	if(!r) return ERROR;
	r->data = e;
	r->next = p->next;
	p->next = r;
	S->length ++;
	return OK;

}

 

//======================================

// Print the elements in a stack

//=======================================

void PrintStack (LinkStack S)
{

	LinkList p = S.Head->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	 } 
	 
}

//=========================

// 计算分值，s为字符串数组，nSize为数组的长度

//========================

int CalPoints(char *s,  int nSize)

{
	LinkStack Sstack;
	InitStack(&Sstack);
	int count = 0,i = 0,e;
	for(;i < nSize;i ++)
	{
		if(s[i] <= '9' && s[i] >= '0')	Push(&Sstack,s[i] - '0');
		else if(s[i] == '+')	
		{
			LinkList p = Sstack.Head->next;
			//while(p->next->next)	p = p->next;
			Push(&Sstack,p->data + p->next->data);
		}
		else if(s[i] == 'D')	Push(&Sstack,2 * GetTop(Sstack));
		else if(s[i] == 'C')	Pop(&Sstack,&e);
	}
	
	LinkList q = Sstack.Head->next;
	while(q)	
	{
		count +=q->data;
		q = q->next; 
	}
	return count;

} 



int main()  

{  
	int n,i = 0;
	char str[n + 1];
	scanf("%d",&n);
	for(;i < n;i ++)	
	{
		getchar(); 
		scanf("%c",&str[i]);
	}
	str[n] = '\0';
	printf("%s",str); 
	printf("%d",CalPoints(str,n));
	
	return OK;

 } 


