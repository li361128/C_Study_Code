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

/***************链表初始化**********************/
int Initlist(LinkList *L)
{
    (*L)=(LinkList)malloc(sizeof(LNode));
    if(L==NULL)
    {
  		printf("内存创建失败\n");
   		return ERROR;
    }
    (*L)->next=NULL;
    //根据键盘值构造链表
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
			printf("初始化失败");
		    return ERROR;
		}
		p->data=x;
		p->next= NULL;
		r->next=p;
		r=p;
	}
	return OK;
}
/******************打印单链表*****************/
void ListPrint(LinkList L)
{
//★★★请补全代码
	LinkList p = L->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");

}
/****************求单链表的长度******************/
int ListLength(LinkList L)
{
//★★★请补全代码
	int total = 0;
	LinkList p = L->next;
	while(p)
	{
		total ++;
		p = p->next;
	}
	return total;

}

/*********元素交换*********************/
int Exchange(LinkList *L)
{
//★★★请补全代码
	int ex = (ListLength(*L) + 1) / 2;
	int i = 1;
	LinkList p = (*L)->next;
	LinkList r = (*L)->next;
	LinkList p_pre = *L;
	while(p && i < ex)
	{
		p_pre = p;
		p = p->next;
		i ++;
	}
	LinkList temp = (*L)->next->next;
	r->next = p->next;
	p_pre->next = r;
	
	p->next = temp;
	(*L)->next = p;
	return 1;

}

/************主函数******************/
int main()
{
	int length;
	LinkList L;
	Initlist(&L);
	ListPrint(L);
	length=ListLength(L);
	printf("%d\n",length);
	Exchange(&L);
	ListPrint(L);
	return 0;
}
