#include <stdio.h>
#include <stdlib.h>

//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE 0
//新建函数类型，表示函数运行结果
typedef int Status;

/*动态单链表的结构体定义*/ 
//定义结构体
typedef int ElemType;
typedef struct LNode
{
    ElemType data; //数据域
    struct LNode* next; //指针域
}LNode, *LinkList;

Status InitList(LinkList *L)
{
    int x,i;
    *L = (LinkList)malloc(sizeof(LNode));
    if(*L == NULL)
    {
        printf("memory malloc failure\n");
        return ERROR;
    }
    (*L)->next = NULL;
        //根据键盘值构造链表
    LinkList r;
    r = *L;
    for(i=0; ;i++)
    {
        scanf("%d",&x);
        if(x == -1)
            break;
        LinkList p = (LinkList)malloc(sizeof(LNode));
        if(!p) 
        {
            printf("initial failure\n");
            return ERROR;
        }
        p->data = x;
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return OK;

}

Status DestoryList(LinkList *L)
{
    LinkList p;
    while(*L) //当L为空时循环结束
    {
        p = (*L)->next; //p指向下一个结点
        free(*L); //释放L
        *L = p;
    }
    return OK;
}

Status ListEmpty(LinkList L)
{
    return (L->next == NULL);
}

Status ClearList(LinkList L) 
{
    LinkList p, q;
    p = L->next; //p指向链表第一个结点
    while (p) //当p指向空时循环结束
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL; //头结点指针域为空
    return OK;
}

int ListLength(LinkList L)
{
   //补全代码
    int total = 0;
	LinkList p = L->next;
    while(p)
    {
    	total ++;
    	p = p->next;
	}
	return total;


}


Status ListTraverse(LinkList L)
{
    LinkList p = L->next;
    while (p) //当p为空时结束循环
    {
        printf("%d ",p->data); 
        p = p->next;
    }
    printf("\n");
    return OK;
}

Status ListOperate(LinkList *L)
{

 //补全代码
 	LinkList p = (*L);
	if(ListEmpty(*L))
	{
		LinkList r;
		r = (LinkList)malloc(sizeof(LNode));
		if(!r)	return ERROR;
		r->data = 0;
		LinkList s;
		s = (LinkList)malloc(sizeof(LNode));
		if(!s)	return ERROR;
		s->data = 0;
		p->next = r;
		r->next = s;
		s->next = NULL;
		return 0;
	}
	int max = p->next->data, min = p->next->data;
	while(p->next)
	{
		if(p->next->data > max)
		{
			max = p->next->data;
		}
		else if(p->next->data < min)
		{
			min = p->next->data;
		}
		p = p->next;
	 }
 	LinkList r;
	r = (LinkList)malloc(sizeof(LNode));
	if(!r)	return ERROR;
	r->data = min;
	r->next = p->next;
	p->next = r;
	
	LinkList s;
	s = (LinkList)malloc(sizeof(LNode));
	if(!s)	return ERROR;
	s->data = max;
	s->next = (*L)->next;
	(*L)->next = s;

	return 1; 
	 

}

int main()
{
    //初始化链表
    LinkList L;
    if (InitList(&L) == ERROR)
    {
        return 0;
    }
    ListTraverse(L);//对应第一行打印输出
    int len = ListLength(L);
    printf("%d\n",len);//对应第二行打印输出
    ListOperate(&L);
    ListTraverse(L);//对应第三行打印输出
    DestoryList(&L);
    return 0;
}
