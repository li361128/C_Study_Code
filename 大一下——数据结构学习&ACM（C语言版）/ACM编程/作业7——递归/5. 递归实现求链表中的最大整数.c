#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct	L_Node
{
	int data;
	struct L_Node *next; 
}LNode,*LinkList;

void InitList_L(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if(!(*L))	return ;
	(*L)->next = NULL;
}

void CreateList_L(LinkList L,int n)
{
	LNode *p = L; 
	
	int arr,i;
	for(i = 0;i < n;i ++)
	{
		scanf("%d",&arr); 
		LNode *r ;
		r = (LinkList)malloc(sizeof(LNode));
		if(!r)	return ;
		r->data = arr;
		r->next = NULL;
		p->next = r;
		p = p->next;
	 } 
}

int find_max(LinkList L)
{
	if(!L|| !L->next)	return 0;
	if(!L->next->next)	return L->next->data;
	return L->next->data >= find_max(L->next) ? L->next->data : find_max(L->next);
}


int main(int argc, char *argv[]) 
{
	int n,i;
	scanf("%d",&n);
	
	LinkList L;
	
	InitList_L(&L);
	
	CreateList_L(L,n);
	
	printf("%d",find_max(L));

	return 0;
}
