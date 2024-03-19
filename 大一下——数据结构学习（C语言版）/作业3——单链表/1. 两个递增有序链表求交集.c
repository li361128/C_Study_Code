#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int ElemType;  
typedef int Status; 
// definition of node structure of singly linked list
typedef struct LNode
{  
    ElemType data;           // data field
    struct LNode *next;       // pointer field
}LNode, *LinkList;

//===========================================

// Initialize  a singly linked list L with head node

//===========================================

Status InitList_L(LinkList* L)
{
 	*L =  (LinkList)malloc(sizeof(LNode));
 	if(!*L) return ERROR;
 	(*L)->next = NULL;
	return OK;
}

//===========================================

// Create a singly linked list L with head node, and with n elements

//===========================================

Status CreateList_L(LinkList L, ElemType a[ ], int n)
{
	LNode *r = L;
	int i = 0;
	for(;i < n;i ++)
	{
		LNode *p ;
		p = (LNode*)malloc(sizeof(LNode));//初始化指针，为其分配内存空间，防止出现内存泄漏和未定义行为 
		p->data = a[i];
		p->next = NULL;
		r->next = p;//将p插入链表中 
		r = p;//更新r的结点，变成指向p的结点 
	}
	return OK; 
}


//======================================

// Insert an element in a list

//=======================================

Status ListInsert_L(LinkList L,int i,ElemType e)
{
	LinkList r = L;
	int j = 0;
	while(r && j < i - 1)
	{
		r = r->next;
		++j;
	}
	if(!r || j > i - 1) return ERROR;
	LinkList s = (LNode*) malloc(sizeof(LNode));
	if(!s) return ERROR;
	s->data = e;
	s->next = r->next;
	r->next = s;
	r = s;
	return OK;
}


//=====================================

// 求两个递增链表La和Lb的交集，得到一个新的链表Lc

//====================================

Status ListIntersection_L(LinkList La, LinkList Lb, LinkList Lc)

{
	int len_c = 0;
	LNode *ra = La->next;
	LNode *rb = Lb->next;
	LNode *rc = Lc;
	while(ra && rb)
	{
		if(ra->data > rb->data)			rb = rb->next;
		else if(ra->data < rb->data)	ra = ra->next;
		else
		{
			ListInsert_L(Lc,++len_c,rb->data);
//			LNode *s ;
//			s = (LNode*)malloc(sizeof(LNode));
//			s->data = ra->data;
//			s->next = NULL;
//			rc->next = s;
//			rc = s;
			ra = ra->next;
			rb = rb->next;
		}
	}
}

//======================================

// Print the elements in a list

//=======================================


void LinkedListPrint(LinkList L)
{
	if (L->next == NULL)
    {
        return;
    }
	LinkList p = L->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

int main()  
{  
	int n,m;
	LinkList La;
	LinkList Lb;
	LinkList Lc;
	InitList_L(&La);
	InitList_L(&Lb);
	InitList_L(&Lc);
	
	scanf("%d",&n);
	int a[n];
	int i = 0;
	for(;i < n;i ++)
		scanf("%d",&a[i]);
	CreateList_L(La,a,n);
	//LinkedListPrint(La);
	
	scanf("%d",&m);
	int b[m];
	i = 0;
	for(;i < m;i ++)
		scanf("%d",&b[i]); 
	CreateList_L(Lb,b,m);

	ListIntersection_L(La,Lb,Lc);

	//LinkedListPrint(La);
	//LinkedListPrint(Lb);v br5
	LinkedListPrint(Lc);
	
	return 0;
}



//
//
//#include <stdio.h>  
//#include <stdlib.h> 
//#include <malloc.h> 
//
//#define ERROR 0
//#define OK 1
//
//typedef int ElemType;  
//typedef int Status; 
//
//// definition of node structure of singly linked list
//typedef struct LNode
//{  
//    ElemType data;           // data field
//    struct LNode *next;      // pointer field
//} LNode, *LinkList;
//
////===========================================
//// Initialize a singly linked list L with head node
////===========================================
//Status InitList_L(LinkList *L)
//{
//    *L = (LinkList)malloc(sizeof(LNode));
//    if (!(*L)) return ERROR;
//    (*L)->next = NULL;
//    return OK;
//}
//
////===========================================
//// Create a singly linked list L with head node, and with n elements
////===========================================
//Status CreateList_L(LinkList L, ElemType a[], int n)
//{
//    LNode *r = L;
//    int i = 0;
//    for (; i < n; i ++)
//    {
//        LNode *p = (LNode*)malloc(sizeof(LNode));
//        if (!p) return ERROR;
//        p->data = a[i];
//        p->next = NULL;
//        r->next = p;
//        r = p;
//    }
//    return OK; 
//}
//
////===========================================
//// 求两个递增链表La和Lb的交集，得到一个新的链表Lc
////===========================================
//Status ListIntersection_L(LinkList La, LinkList Lb, LinkList Lc)
//{
//    int len_c = 0;
//    LNode *ra = La->next;
//    LNode *rb = Lb->next;
//    LNode *rc = Lc; // 指向 Lc 的头结点
//    while (ra && rb)
//    {
//        if (ra->data > rb->data) rb = rb->next;
//        else if (ra->data < rb->data) ra = ra->next;
//        else
//        {
//            LNode *s = (LNode*)malloc(sizeof(LNode));
//            if (!s) return ERROR;
//            s->data = ra->data;
//            s->next = NULL;
//            rc->next = s;
//            rc = s;
//            ra = ra->next;
//            rb = rb->next;
//        }
//    }
//    return OK;
//}
//
////===========================================
//// Print the elements in a list
////===========================================
//void LinkedListPrint(LinkList L)
//{
//    if (L->next == NULL)
//    {
//        //printf("The linked list is empty.\n");
//        return;
//    }
//    LinkList p = L->next;
//    while(p)
//    {
//        printf("%d ",p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//
//int main()  
//{  
//    int n, m;
//    LinkList La, Lb, Lc;
//    InitList_L(&La);
//    InitList_L(&Lb);
//    InitList_L(&Lc);
//    
//    //printf("Enter the number of elements in list La: ");
//    scanf("%d", &n);
//    int a[n],i;
//    //printf("Enter the elements of list La in increasing order: ");
//    for (i = 0; i < n; i++)
//        scanf("%d", &a[i]);
//    CreateList_L(La, a, n);
//    
//    //printf("Enter the number of elements in list Lb: ");
//    scanf("%d", &m);
//    int b[m];
//    //printf("Enter the elements of list Lb in increasing order: ");
//    for (i = 0; i < m; i++)
//        scanf("%d", &b[i]);
//    CreateList_L(Lb, b, m);
//
//    ListIntersection_L(La, Lb, Lc);
//
//    LinkedListPrint(Lc);
//    
//    return 0;
//}

