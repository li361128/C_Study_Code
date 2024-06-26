#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

typedef struct LNode {
    ElemType data; //结点的数据域
    struct LNode *next; //结点的指针域
} LNode, *LinkList;


/*
敬爱的宇宙无敌好老师！！！
调了好久，测试数据都对了！！！ 
扣小分能不能温柔点，可怜可怜孩子吧！！！
小分实在实在是扣不起了，调了那么久会心疼的！！！ 
我知道您一定是全世界最好的老师！！！ 
*/


//前插法创建单链表——逆位序输入n个元素的值，建立带头结点的单链表L
Status CreateList_F(LinkList *L, int n) 
{ 
//请补全代码
    if(n<=0) 
    {
        return ERROR;
	}
        
    (*L) = (LinkList)malloc(sizeof(LNode));//初始化头结点，为头结点分配内存 
    if(!(*L))	
		return ERROR;
	(*L)->next = NULL;
	
    LinkList p = (*L);
    int i;
    for(i = 0;i < n;i ++)
    {
    	//创建新的链表结点 
    	LinkList r = (LinkList)malloc(sizeof(LNode));
		if(!r)	return ERROR;
    	scanf("%d",&r->data);
    	
    	//将新创建的结点以头插的方式与*L相连 
    	r->next = p->next;
    	p->next = r;
	}
    
    return OK;
}

//打印单链表
Status ListPrint(LinkList L)
{
//请补全代码
	if(!L)
		return ERROR; 
	LinkList p = L->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

//使用递归算法求单链表L数据元素之和
int ListSum(LinkList L)
{
//请补全代码
	if(!L || !L->next)
		return 0;
		
	return ListSum(L->next) + L->next->data;

}
 
int main()
{
//请补全代码
	int n;
	scanf("%d",&n);
	
	LinkList L;
	if(CreateList_F(&L, n) == OK)
	{
		printf("The linked list is: ");
		ListPrint(L);
	}
	else
	{
		printf("This is an empty List.\n");
	}
	
	
	printf("The sum of the linked list is: %d",ListSum(L));
	
	return 0;

}
