 #include <stdio.h>

#include "stdio.h"

#include "malloc.h"

#include "stdlib.h"

 

#define ERROR -1

#define OK 1

 

typedef struct Lnode

{

       int data;

      struct Lnode *next;

}LNode,*LinkList;

 

int Initlist(LinkList *L)

{

     (*L)=(LinkList)malloc(sizeof(LNode));

     if(L==NULL)

     {

                printf("Memory failure \n");

              return ERROR;

     }

     (*L)->next=NULL;

 

       LinkList r;

       r=*L;

       int x;

       int i;

       for(i=0; ; i++)

       {

              scanf("%d",&x);

              if(x==-1)

              break;

              LNode *p=(LinkList)malloc(sizeof(LNode));

              if(!p)

              {

                     printf("Initialization failure ");

                  return ERROR;

              }

              p->data=x;

              p->next= NULL;

              r->next=p;

              r=p;

       }

      return OK;

}

 

void ListPrint(LinkList L)

{

       LNode *p;

       for(p=L->next;p!=NULL;p=p->next){

              printf("%d ",p->data);

       }

      

}

 

int ListLength(LinkList L)

{

       //★★★请补全代码
       LNode *p = L->next;
       int count = 0;
	   while(p)
	   {
	   		count ++;
	   		p = p->next;
		} 
		return count;

}

 

 

void MoveMin(LinkList *L)

{

//★★★请补全代码
	int min = (*L)->next->data;
	LNode *p = (*L)->next;
	while(p)
	{
		if(p->data < min)
		{
			min = p->data;
		}
		p = p->next;
	}
	
	LNode *min_p = (*L)->next;
	LNode *min_pre = (*L);
	LNode *r = (*L);
	int i = 0;
	for(;i < ListLength(*L);i ++)
	{
		if(min_p->data != min)
		{
			min_pre = min_pre->next;
			min_p = min_p->next;
		}
		else if(min_p->data == min)
		{
			min_pre->next = min_p->next;
			min_p->next =  r->next;
			r->next = min_p;
			return ;
		}
	}
}

 

 

int SumToNewlist(LinkList *L)

{

//★★★请补全代码
	int sum = 0,i = 1;
	LNode *p = (*L)->next;
	while(p)
	{
		sum += p->data;
		p = p->next;
	}
	LNode *r ;
	r = (LNode*)malloc(sizeof(LNode));
	r->data = sum;
	r->next = NULL;
	LNode *q = (*L);
	while(q->next)
	{
		q = q->next;
	}
	q->next = r;
	return 1;

}

 

int main()

{

       int length;

       LinkList L;

       Initlist(&L);

        printf("The original linked list is：");

       ListPrint(L);

       printf("\nThe length of list is：");

       length=ListLength(L);

       printf("%d ",length);

       MoveMin(&L);

       printf("\nAfter moving the minimum, the linked list is: ");

       ListPrint(L);

       printf("\nAfter inserting the sum, the new list is: ");

       SumToNewlist(&L);

       ListPrint(L);

       return 0;

}


