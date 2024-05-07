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
	(*L) = (LinkedList)malloc(sizeof(LNode));
	if(!(*L))	return ERROR;
	(*L)->next = NULL;
	return OK; 
 

}

 

//===========================================

// 输入若干整数（以输入-1作为结束条件，-1不包含在单链表中），用递归方法创建一个不带头结点的单链表。

//===========================================

Status CreateList_L(LinkedList L)

{
	ElemType input;
	scanf("%d",&input);
	if(input == -1)
	{
		L->next = NULL;
		return OK;
	}
	L->next = (LinkedList)malloc(sizeof(LNode));
	if(!L->next)	return ERROR;
	L->next->data = input;
	CreateList_L(L->next);
	return OK;
 

}



//======================================

// Print the elements in a list

//=======================================

void LinkedListPrint(LinkedList L)

{
	if(!L->next)	return ;
	printf("%d ",L->next->data); 
	LinkedListPrint(L->next);
	printf("\n");

}



int main()   

{   
	LinkedList La;
	
	InitList_L(&La);
	
	CreateList_L(La);
	
	LinkedListPrint(La);
	
	return 0;

}  
