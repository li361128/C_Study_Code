//第一问代码有瑕疵， 扣1分
//第二问逻辑轻度复杂， 扣1分
//第三问效率低， 扣1分
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
       int count = 0;	//count 作计数器
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
	//在遍历链表寻找最小值时就维护好最小值所在结点及其前驱 
	// 如此便不需要记录最小值data， 不需要后续再遍历一次 
	LNode *min_p = (*L)->next;
	LNode *min_pre = (*L);//记录最小值所在节点的前驱结点，以便删除操作
	LNode *pre = (*L);
	LNode *p = (*L)->next;
	while(p)
	{
		if(p->data < min_p->data)
		{
			min_pre = pre;//找到链表的最小值
			min_p = p;
		}
		pre = p;
		p = p->next;
	}
	
	if(min_p != (*L)->next)
	{
		min_pre->next = min_p->next;
		min_p->next = (*L)->next;
		(*L)->next = min_p; 
	}
	
	
//	int i = 0;
//	for(;i < ListLength(*L);i ++)
//	{
//        if(min_p->data == min)
//		{//检索最小值所在节点，并进行移动
//			min_pre->next = min_p->next;//去除原链表中最小值所在节点
//			min_p->next =  r->next;//将最小值结点插入到首元结点
//			r->next = min_p;
//			return ;
//		}
//        min_pre = min_pre->next;
//		min_p = min_p->next;
//	}

}

int SumToNewlist(LinkList *L)

{

//★★★请补全代码
	int sum = 0;
	LNode *p = (*L)->next;
    LNode *tail = NULL;
	while(p)
	{
		sum += p->data;//求和
        if (p->next == NULL) {
            tail = p; // Keep track of the last node
        }
		p = p->next;
	}
    //创建sum节点
	LNode *r ;
	r = (LNode*)malloc(sizeof(LNode));
	r->data = sum;
	r->next = NULL;
    
    //插到尾节点
//	LNode *q = (*L);
//	while(q->next)
//	{
//		q = q->next;
//	}
	tail->next = r;
    
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
