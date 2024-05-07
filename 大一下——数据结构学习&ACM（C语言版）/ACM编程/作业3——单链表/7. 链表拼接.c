#include <stdio.h>   

#include <stdlib.h>   

#include <malloc.h>



#define ERROR 0

#define OK 1

#define TRUE 1

#define FALSE 0

typedef int ElemType;   

typedef int Status;



  

// definition of node structure of singly linked list

typedef struct L_node

{   

    ElemType data;           // data field 

    struct L_node *next;       // pointer field

}LNode, *LinkedList;

  

//===========================================

// Initialize  a singly linked list L with head node

//===========================================

Status InitList_L(LinkedList *L)

{
	*L = (LNode*)malloc(sizeof(LNode));
	if(!(*L))	return ERROR;
	(*L)->next = NULL;
	return OK;
}



//===========================================

// Create a singly linked list L with head node, and with n elements

//===========================================

Status CreateList_L(LinkedList *L, int a[ ], int n)

{
	LNode *r = (*L);
	int i = 0;
	for(;i < n;i ++)
	{
		LNode *p ;
		p = (LNode*)malloc(sizeof(LNode));
		p->data = a[i];
		p->next = NULL;
		r->next = p;
		r = p;
	}
 	return OK;
}



//===========================================

//  Merge two singly linked lists 

//===========================================

int Merge_L(LinkedList *ha,int len_a,LinkedList *hb,int len_b, LinkedList *hc )

{
	LNode *a = (*ha)->next;
	LNode *b = (*hb)->next;
	LNode *c = *hc;
	LNode *c1;
	c1 = (LNode*)malloc(sizeof(LNode));
	if(len_a > len_b)
	{
		while(b)
		{
			c1 = b;
			c->next = c1;
			c= c1;
			b = b->next;
		}
		while(a)
		{
			c1 = a;
			c->next = c1;
			c= c1;
			a = a->next;
		}
	}
	else
	{
		while(a)
		{
			c1 = a;
			c->next = c1;
			c= c1;
			a = a->next;
		}
		while(b)
		{
			c1 = b;
			c->next = c1;
			c= c1;
			b = b->next;
		}
	}
 

}





//======================================

// Print the elements in a list

//=======================================

void LinkedListPrint(LinkedList L)

{ 
	LNode *p = L->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}





int main()   

{   
	LNode *La;
	LNode *Lb;
	LNode *Lc;
	InitList_L(&La);
	InitList_L(&Lb);
	InitList_L(&Lc);
	int n,m,i = 0;
	scanf("%d",&n);
	int a[n];
	for(;i < n;i ++)	scanf("%d",&a[i]);
	CreateList_L(&La,a,n);
	scanf("%d",&m);
	int b[m];
	for(i = 0;i < m;i ++)	scanf("%d",&b[i]);
	CreateList_L(&Lb,b,m);
	Merge_L(&La,n,&Lb,m,&Lc);
	LinkedListPrint(Lc);

}  
