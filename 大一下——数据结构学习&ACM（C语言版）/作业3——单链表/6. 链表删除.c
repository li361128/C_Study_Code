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

    struct L_node* next;       // pointer field

}LNode, * LinkList;



//===========================================

// Initialize  a singly linked list L with head node

//===========================================

Status InitList_L(LinkList *L)

{
	(*L) = (LNode*)malloc(sizeof(LNode));
	(*L)->next = NULL;
	return OK;

}



//===========================================

// Create a singly linked list L with head node, and with n elements

//===========================================

Status CreateList_L(LinkList* L, ElemType a[], int n)

{
	LNode *p = *L;
	int j = 0;
	for(;j < n;j ++)
	{
		LNode*r ;
		r = (LNode*)malloc(sizeof(LNode));
		r->data = a[j];
		r->next = NULL;
		p->next = r;
		p = r;
	}
	return OK;
}

void Delete_List(LinkList L,int i)
{
	LNode*prev = L;
	int j = 0;
	while(prev && j < i - 1)
	{
		prev = prev->next;
		j ++;
	}
	if(!prev || j > i - 1) return ;
	LinkList r = prev->next;
	prev->next = r->next;
	free(r);
	return ;
}

//===========================================

//  删除位序为偶数的结点，并返回删除结点的总数

//===========================================

int Delete_L(LinkList *L,int len)

{
	int i = len / 2;
	int j = 2 * i;
	int count = 0;
	for(;j >1;j -=2)	
	{
		Delete_List(*L,j);
		count ++;
	}
	return count;
}





//======================================

// Print the elements in a list

//=======================================

void LinkedListPrint(LinkList L)

{
	LNode *p = L->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	return;
}





int main()

{
	LNode *L;
	InitList_L(&L);
	int i = 0,n;
	scanf("%d",&n);
	int arr[n];
	for(;i < n;i ++) scanf("%d",&arr[i]);
	CreateList_L(&L,arr,n);
	int tot = Delete_L(&L,n);
	printf("%d\n",tot);
	LinkedListPrint(L);
	return OK;


}


