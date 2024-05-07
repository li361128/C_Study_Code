#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int ElemType;  
typedef int Status; 
typedef struct L_node
{  
    int data;           
    struct L_node *next;       
}LNode, *LinkedList;



Status InitList_L(LNode *L)
{
	L=(LNode *)malloc(sizeof(LNode));
	L->next=NULL;
	return OK;
}
 

Status CreateList_L(LNode *L,int *a,int n)
{
	int i;
	LNode *r;
	r=L;
	for(i=0;i<n;i++)
	{
		LNode *p;
		p=(LNode *)malloc(sizeof(LNode));
		p->data=a[i];
		p->next=NULL;
		r->next=p;
		r=p;
	}
}


//Status InversePrint(LNode *L)
//{
//	
//	if(!L) 
//		return OK;
//	InversePrint(L->next);
//	printf("%d",L->data);
//	return OK;
//}

//Status InverseList(LNode *L)
//{
//	LNode *p,*q;
//	p=L->next;
//	L->next=NULL;
//	while(p)
//	{
//		q=p->next;
//		p->next=L->next;
//		L->next=p;
//		p=q;
//	}
//	return OK;
//}

Status InversePrint(LinkedList p){

   //逆序打印不带头结点的单链表的元素    

   if(!p) return OK;

   InversePrint(p->next);

   printf("%d",p->data);

   return OK;

}// 

int main()  
{  
	LNode *L;
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	InitList_L(L);
	CreateList_L(L,a,n);
	LNode *p;
	p=L->next;
	InversePrint(p);//逆置打印 
	
	
	InversePrint(L);//逆置链表后逆置打印 
	p=L->next;
	printf("\n");
	InversePrint(p);
}
