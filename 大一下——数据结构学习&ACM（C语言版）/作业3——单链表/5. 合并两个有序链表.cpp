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

 

//============================

// Initialize a singly linklist L with head node,

//===========================

Status InitLinkList(LinkList &L)

{
	(*L) = (LNode*)malloc(sizeof(LNode));
	//if(!(*L)) return ERROR;
	(*L)->next = NULL;
	return OK;
} 

//===========================================

// Create a singly linked list L with head node, and with n elements

//===========================================

Status CreateList_L(LinkList &L, int a[ ], int n) 

{
	LNode *p ;
	p = (LNode*)malloc(sizeof(LNode));
	int i = 0;
	for(;i < n;i ++)
	{
		LNode *r ;
		r = (LNode*)malloc(sizeof(LNode));
		r->data = a[i];
		p->next = r;
		r->next = NULL;
		p = r;
	}
	return OK;
	
 

}



//===========================================

//   merge two singly linked list La and Lb into Lc

//===========================================

void Merge_L(LinkList &La,LinkList &Lb, LinkList &Lc)

{
	LNode *a = (*La)->next;
	LNode *b = (*Lb)->next;
 	while(a && b)
 	{
 		if(a->data >= b->data)
 		{
 			(*Lc)->next = b;
 			b = b->next;
		 }
		 else if(a->data < b->data)
		 {
		 	(*Lc)->next = a;
		 	a = a->next;
		 }
	 }
	 while(a)
	 {
	 	(*Lc)->next = a;
		a = a->next;
	 }
	 while(b)
	 {
	 	(*Lc)->next = b;
 		b = b->next;
	 }

}



//======================================

// Print the elements in a list

//=======================================

void LinkedListPrint(LinkedList L)

{
	LNode* p = L;
	while(p->next)
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
	InitLinkList(&La);
	InitLinkList(&Lb);
	InitLinkList(&Lc);
	int n,m,i = 0;
	scanf("%d",&n);
	int a[n];
	for(;i < n;i ++) scanf("%d",&a[i]);
	CreateList_L(&La,a,n);
	scanf("%d",&m);
	int b[m];
	for(i = 0;i < m;i ++)	scanf("%d",&b[i]);
	CreateList_L(&Lb,b,m);
	
	Merge_L(&La,&Lb,&Lc);
	
	LinkedListPrint(Lc);
	
	return OK;

}  


