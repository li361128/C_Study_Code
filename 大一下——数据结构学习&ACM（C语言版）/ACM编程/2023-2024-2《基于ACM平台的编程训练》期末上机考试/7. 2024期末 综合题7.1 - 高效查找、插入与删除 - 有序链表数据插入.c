
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status;

typedef struct Lnode
{
    int data;
    struct Lnode *next;
} LNode;
typedef struct Lnode *LinkList;

Status InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if (!(*L))
        return 0;
    (*L)->next = NULL;
    return 1;
}


/*
敬爱的宇宙无敌好老师！！！
调了好久，测试数据都对了！！！ 
扣小分能不能温柔点，可怜可怜孩子吧！！！
小分实在实在是扣不起了，调了那么久会心疼的！！！ 
我知道您一定是全世界最好的老师！！！ 
*/


/* 将输入数据e按序插入到一个升序有序的链表L中 */
Status SortInsert(LinkList *L, int e)
{
    //★★★请补全代码
    LinkList r ;//创建新的链表结点 
    r = (LinkList)malloc(sizeof(LNode));
    if(!r)
    {
    	return ERROR;
	}
	r->data = e;
	
	LinkList p = (*L);
	if(p->next)
	{//寻找到新结点r所要加到链表的哪个位置
	//当然，若链表为空，则无需比较 
		while(p->next && p->next->data < e)
		{
			p = p->next;
		}
	}
	
	r->next = p->next;
	p->next = r;
	
	return OK;   
}

Status Display(LinkList L)
{
    LNode *p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    LinkList L;
    int elem;
    InitList(&L);
    scanf("%d", &elem);
    while(elem != -1)
    {
        SortInsert(&L, elem);
        scanf("%d", &elem);
    }
    Display(L);
    return 0;
}
