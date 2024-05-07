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
	LNode*p = L; 
	int len = 0;
	while(p->next)
	{
		len ++;
		p = p->next; 
	 } 
	 return len;

}





Status ListDelete(LinkList L, int i, ElemType* e)

{

    LinkList p = L;

    int j = 0; //计数器



//当第i个结点为空，或者j = i-1时结束循环，此时p指向第i-1个结点

    while (p->next && j < i - 1)

    {

        p = p->next;

        j++;

    }



    if (!(p->next) || j > i - 1) return ERROR;



    LinkList q = p->next; //q保存删除结点地址

    p->next = p->next->next; //删除

    *e = q->data; //e存放删除节点的数据

    free(q); //释放



    return OK;

}



Status ListTraverse(LinkList L)

{

    LinkList p = L->next;

    while (p) //当p为空时结束循环

    {

        printf("%d ",p->data); //每一个数据都进行visit函数操作，例如visit可以是打印函数

        p = p->next;

    }

    printf("\n");

    return OK;

}

Status ListInsert(LinkList L,int i,ElemType e)
{
	LinkList p = L;
	int j = 0;
	while(p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i - 1)	return ERROR;
	LNode *r ;
	r = (LNode*)malloc(sizeof(LNode));
	if(!r) return ERROR;
	r ->data = e;
	r->next = p->next;
	p->next = r;
	return OK;
}



Status ListOperate(LinkList L)

{

//补全代码
	if(ListEmpty(L)) 
	{
		printf("0 0");
		return OK;
	}
	int max = L->next->data,min = L->next->data;
	LNode *p = L->next;
	while(p)
	{
		if(max < p->data)	max = p->data;
		if(min > p->data)	min = p->data;
		
		p = p->next;
	}
	ListInsert(L,1,max);
	ListInsert(L,ListLength(L) + 1,min);
	return OK;
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

    ListOperate(L);

    ListTraverse(L);//对应第三行打印输出

    DestoryList(&L);

    return 0;

}

