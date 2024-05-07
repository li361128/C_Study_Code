#include <stdio.h>
#include <stdlib.h>

typedef struct L_Node
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
	int i ,arr;
	LNode *p = L;
	for(i = 0;i < n; i ++)
	{
		scanf("%d",&arr);
		LNode *r;
		r = (LinkList)malloc(sizeof(LNode));
		r->data = arr;
		r->next = NULL;
		p->next = r;
		p = p->next;
	}
}

int Count_Node(LinkList L)
{
	if(!L->next)	return 0;
	return 1 + Count_Node(L->next);	
} 


int main(int argc, char *argv[]) 
{
	int n;
	scanf("%d",&n);
	
	LinkList L;
	
	InitList_L(&L);
	
	CreateList_L(L,n);
	
	printf("%d",Count_Node(L));
	
	return 0;
}
