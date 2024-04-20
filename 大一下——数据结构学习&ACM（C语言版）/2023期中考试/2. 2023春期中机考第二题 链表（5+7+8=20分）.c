#include <stdio.h>

#include <stdlib.h>

#define ERROR -1

#define OK 1



typedef struct Lnode

{

	int data;

	struct Lnode *next;

}LNode,*LinkList;



// 创建带头结点的单链表

int CreateList(LinkList *L)

{

	*L=(LinkList)malloc(sizeof(LNode));

	if((*L)==NULL)

	{

		printf("Memory failure\n");

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

			printf("Initialization failure");

			return ERROR;

		}

		p->data=x;

		p->next= NULL;

		r->next=p;

		r=p;

	}

	return OK;

}



//打印单链表

void ListPrint(LinkList L)

{

	LNode *p;

	for(p=L->next;p!=NULL;p=p->next)

	{

		printf("%d ",p->data);

	}

}



//求单链表长度

int ListLength(LinkList L)

{

	//★★★请补全代码
	int len = 0;
	 LinkList p = L->next;
	 while(p)
	 {
	 	len ++;
	 	p = p->next;
	 }
	return len;






}



//删除单链表的倒数第x个元素, 参数length为单链表长度，

//如果操作成功，返回OK，否则返回ERROR

int DeleteX(LinkList  *L,int length, int x)

{
	
	if(x > ListLength(*L))
	{
		printf("\nThe x value is not valid");
		return 0;
	}

	//★★★请补全代码
	int i = 0;
	LinkList p = (*L);
	while(p->next && i < length - x)
	{
		p = p->next;
		i ++;
	}
	LinkList s = p->next;
	p->next = s->next;
	free(s);
	return OK;







}



//单链表元素求和，并将累加和添加到单链表尾部

//如果操作成功，返回OK，否则返回ERROR

int AppendSumToList(LinkList *L)

{

	//★★★请补全代码
	int sum = 0;
	LinkList p = (*L);
	while(p->next)
	{
		sum += p->next->data;
		p = p->next;
	}
	LinkList s;
	s = (LinkList)malloc(sizeof(LNode));
	if(!s)	return ERROR;
	s->data = sum;
	s->next = NULL;
	p->next = s;
	return 1;
	






} 



int main()

{

	int length;

	int x;

	LinkList L;

	CreateList(&L);

	scanf("%d",&x);
	


	printf("The original linked list is：");

	ListPrint(L);

	printf("\nThe length of list is：");

	length=ListLength(L);

	printf("%d ",length);
	


	DeleteX (&L,length, x);

	printf("\nAfter deleting the element, the linked list is: ");

	ListPrint(L);

	printf("\nAfter inserting the sum, the new list is: ");

	AppendSumToList(&L);

	ListPrint(L);

	return 0;

}
