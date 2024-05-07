#include <stdio.h>
#include "stdlib.h"
#include <malloc.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE -2

typedef struct {
    char *ch;   // Pointer to the dynamic array storing the characters of the string
    int length; // Length of the string
} HString;

typedef char SString[MAXSIZE + 1];

void StrAssign(SString S,char *str)
{
	int i = 1;
	for(;str[i - 1] != '\0';i ++)
	{
		S[i] = str[i - 1]; 
	}
	S[i] = '\0';
	S[0] = i - 1;
	return ;
 } 

Status StrInsert(HString *S,int pos ,HString T)
{
	if(pos < 1 || pos > S->length)	return ERROR;
	if(!T.length) 	return ERROR;
	S->ch = (char*)realloc(S->ch,(S->length + T.length + 1))
	if(!S->ch)	return ERROR;
	int i = 0;
	for(i = S->length;i >= pos;i --)
	{
		S->ch[i + T.length - 1] = S->ch[i - 1];
	}
	for(i = 0;i < T.length;i ++)
	{
		S->ch[pos + i - 1] = T->ch[i]; 
	}
	return OK;
 } 
 
 typedef char SString[MAXSIZE + 1];
 
 Status MyStrInsert(SString T,int pos,SString sub)
 {
 	int i = 0;	
 	if(pos < 1 || pos > T[0] + 1)	return ERROR;
	if(T[0] + sub[0] < MAXSIZE)
	 {
	 	//完全插入
		 for(i = T[0];i >= pos;i --)
		 {
		 	T[i + sub[0]] = T[i]; 
		  } 
		  for(i = pos;i < pos + sub[0];i ++)
		  {
		  	T[i] = sub[i - pos + 1];
		  }
		  T[0] = T[0] + sub[0];
	  } 
	else
	{
		//部分插入
		for(i = pos;i <pos + sub[0] && i <= MAXSIZE;i ++)
		{
			T[i] = sub[i - pos + 1];	
		}
		T[0] = MAXSIZE; 
	}
	return OK;
 }

Status StrDelete(HString *S,int pos,int len)

{
	if(pos < 1 || pos + len - 1 > S->length)	return ERROR;
	int i = 0;
	for(i = pos + len;i > pos - 1;i ++)
	{
		S->ch[i - len] = S->ch[i]; 
		 
	}
	S.length -= len;
	return OK;
}

int Index(SString S,SString T,int pos)
{
	if(pos >= 1 && pos <= S[0])
	{
		int i = pos;
		int j = 1;
		while(i <= S[0] && j <= T[0])
		{
			if(S[i] == T[i])
			{
				i ++;j ++;
			}
			else
			{
				i = i - j + 2;
				j = 1;
			}
		}
		if(j > T[0])	return i - T[0];
		else return 0;
	}
	else return ERROR;
}

Status Replace(SString S,SString T,SSTring V)
{
	int i = 1;
	for(!T[0])	return ERROR;
	do
	{
		i = Index(S,T,i);
		if(i)
		{
			StrDelete(&S,i,T[0]);
			StrInsert(&S,i,V);
			i += V[0]; 
		}
	}while(i);
	return Ok;
}

Status InitString(HString *T)
{
	T->length = 0;
	T->ch = NULL;
	return OK;
}

Status ClearString(HString *S)
{
	if(S->ch)
	{
		free(S->ch);
		S->ch = NULL;
		S->length = 0;
	}
	return OK;
}

Status StrAssign(HString *T,char *chars)
{
	int i = strlen(chars);
	if(!i)
	{
		T->ch = NULL;
		T->length = 0;
	}
	else
	{
		T->ch = (char*)malloc((i + 1) * sizeof(char));
		if(!T->ch)	return OK;
		int i = 0;
		for(j = 0;j < i;j ++)
		{
			T->ch[j] = chars[j];
		}
	}
	return OK;
}

#define MAXQSIZE 100

typedef struct 
{
	int *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue *Q)
{
	Q->base = (int *)malloc(MAXQSIZE *sizeof(int));
	if(!Q->base)	return ERROR;
	Q->front = Q->rear = 0;
	return OK;
}

int QueueEmpty(SqQueue Q)
{
	return Q.front == Q.rear ? OK : ERROR;
}

Status GetHead(SqQueue Q,QElemType *e)
{
	if(QueueEmpty(Q))	return ERROR;
	*e = Q.base[Q.front];
	return OK;
}

Status DeQueue(SqQueue *Q,QElemType *e)
{
	if(QueueEmpty(Q))	return OK;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK; 
}

Status EnQueue(SqQueue Q)
{
	if((Q->rear + 1) % MAXQSIZE == Q->front) 
	{
		return ERROR;
	}
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1)%MAXSIZE;
	return OK; 
 } 
 void PrintQueue(SqQueue Q)
 {
 	int i = Q.front;
 	while(i != Q.rear)
 	{
 		printf("%d ",Q.base[i]);
 		i = (i + 1) % MAXQSIZE;
	 }
	 printf("\n");
}

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
 } LinkQueue;
 
 Status InitQueue(LinkQueue *Q)
{
 	Q->front = (QNode*)malloc(sizeof(QNode));
 	if(Q->front == NULL)	return ERROR;
 	Q->rear = Q->front;
 	Q->rear->next = NULL;
 	return OK;
} 

Status DeQueue(LinkQueue *Q,QElemType * e)
{
	QNode *p;
	if(Q->front == Q->rear)	return ERROR;
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if(p == Q->rear)
	{
		Q->rear = Q->front;
	}
	return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e)
{
	QNode *p;
	p = (QNode*)malloc(sizeof(QNode));
	if(p == NULL)	return ERROR;
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p; 
	return OK;
}

int DestroyQueue(LinkQueue *q) 

{
	if(q->front == NULL)	retrun 0;
	while(q->len)
	{
		DeQueue(q);
	}
	q->front = q->rear = NULL;
	return 1;
}

int DestoryQueue(LinkQueue *q)
{
	if(q->front == NULL)	return ERROR;
	while(q)
	{
		DeQueue(q);
	}
	q->front = q->rear = NULL; 
}

typedef struct 
{
	char *base;
	char* top;
	int stackSize ;
}SqStack;

Status InitStack(SqStack *S)
{
	S->base = (char*)malloc(sizeof(char));
	if(!S->base)	return ERROR;
	S->top = S->base ;
	S->stackSize = 100;
	return OK; 
} 
Status Push(SqStack *S,char *e)
{
	if(S->top - S->base >= S->stackSize)	return ERROR;
	*S->top ++= e;
	return OK;
}
Status Pop(SqStack *S,char *e)
{
	if(S->top == S->base)	return OK;
	*e = *--S->top;
	return OK;
 } 
 char GetTop(SqStack S)
 {
 	if(S->top != S->base)	return *(S->top - 1);
 }
 
 Status DestoryStack(SqStack S)
 {
 	free(S->base);
 	S->base = S->top = NULL;
	 S->stackSize = 0;
	 if(!S->base)	printf("毁坏成功");
	 return OK; 
}
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void DisplayList(LinkList L)
{
	LNode *p,*p,*r;
	q = L->next;
	p = L->next->next;
	while(p)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
	p->next = NULL;
}

void Reverse_List(LinkList L)
{
	LNode *p,*q,*r;
	q = L->next;
	p = L->next->next;
	while(p)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = =r;
	}
	q->next = NULL;
}

int Index(SString T,SString T,int pos)
{
	if(pos < 1 || pos > S[0])	return ERROR;
	int i = pos;
	int j = 1;
	while(i <= S[0] && j <= T[0])
	{
		if(S[i] == T[i])
		{
			i ++;j ++;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
		if(j > T[0])	return i - T[0];
		else 	return 0;
	}
	return 0;
}

