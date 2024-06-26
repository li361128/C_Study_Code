//±àÐ´ListLength_LºÍGetMaxº¯Êý

#define _CRT_SECURE_NO_WARNINGS
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
ElemType data;          // data field
struct L_node *next;    // pointer field
}LNode, *LinkList;

//===========================================
// Create a singly linked list L with head node, and with n elements
//===========================================
Status CreateList_L(LinkList *L, int n)
{
	LinkList head,p, q;
	int i;
	
	p = (LinkList)malloc(sizeof(LNode)); //create an empty list
	if (!p) return ERROR;
	p->next = NULL;
	head = p;
	for (i = 0; i < n; i++)
	{
		q = (LinkList)malloc(sizeof(LNode));    //make a new node
		if (!q) return ERROR;
		scanf("%d", &q->data);                    //enter element data from keyboard
		
		q->next = NULL;
		p->next = q;
		p = q;
	}
	*L=head;
	return OK;
}

//======================================
//Print all elements of the linked list
//=======================================
void LinkedListPrint(LinkList L)
{
	LinkList p = L->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

//=========================================
// Get the length of the list
//=========================================
int ListLength_L(LinkList L)
{
	LinkList p = L->next;
	int total = 0;
	while(p)
	{
		p = p->next;
		total ++;
	 } 
	 return total;
}

//=========================================
//Find the maximum node and return the value
//the pointer of the Maxnode is returned by p.
//=========================================
int GetMax(LinkList L, LinkList *pMax)
{
	LinkList p = L->next->next;
	*pMax = L->next;
	while(p)
	{
		if(p->data > (*pMax)->data)	*pMax = p;
		p = p->next;
	}
	return (*pMax)->data;
}

int main()
{

	LinkList LA;
	int len;
	
	// Create a singly linked list with elements of 21, 18, 30, 75, 42, 56
	
	CreateList_L(&LA, 6);
	
	// print out the linked list
	LinkedListPrint(LA);
	
	// get the length
	len = ListLength_L(LA);
	printf("the length of the list is %d\n", len);
	
	//get the maxmum value
	int maxVal;
	LinkList pMaxNode; // pointer of the Maxnode;
	
	maxVal = GetMax(LA, &pMaxNode);
	printf("the maximum value is %d\n", maxVal);

	return 0;
}


