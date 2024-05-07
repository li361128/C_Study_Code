#include<stdio.h>

#include<stdlib.h>



#define ERROR 0

#define OK 1



typedef int Status;



typedef struct Node

{

    int data;

    struct Node *next;

} LNode;

typedef LNode *LinkList;



Status InitList(LinkList *L)

{

    *L = (LinkList)malloc(sizeof(LNode));

    if (*L == NULL)

        return ERROR;

    (*L)->next = NULL;

    return OK;

}



//int int_mult(LinkList *L, int base) 
//{
//	
//	int carry = 0;
//	LNode *p = (*L);
//	LNode *pre = NULL;
//	
//	while(p)
//	{
//		p->data = p->data * base + carry;
//		carry = p->data / 10;
//		p->data = p->data % 10;
//		pre = p;
//		p = p->next;
//	}
//	
//	if(!p && carry)
//	{
//		p = (LinkList)malloc(sizeof(LNode));
//		if(!p)	return ERROR;
//		p->data = carry;
//		p->next = NULL;
//		pre->next = p;
//	}
//	return OK;
//}



//统计计算结果中0-9出现个数    

void CountNum(LinkList L, int *num)

{

//★★★请补全代码
	LinkList p = L->next;
	while(p)
	{
		num[p->data]  ++;
		p = p->next;
	 } 

}



Status InversePrint(LinkList p){

   //逆序打印不带头结点的单链表的元素    

   if(!p) return OK;

   InversePrint(p->next);

   printf("%d",p->data);

   return OK;

}// 



int main()

{

    int a,n; /* a为底数(0<a<9)，n为指数 */

    int len=0;

    int num[10]; /* 用于统计计算结果中0-9出现次数 */

    LinkList p;

    LinkList L;

    InitList(&L);

    scanf("%d%d",&a,&n);

    int i;

    for(i=0; i<10; i++)

        num[i]=0;        

    /* 生成表头节点并放入1 */

    p=(LinkList)malloc(sizeof(LNode));

    if(p==NULL) return ERROR;

    p->data=1;

    p->next=NULL;

    L->next=p;

    /* 反复调用乘a操作n次 */

    for(i=0; i<n; i++)

        int_mult(&L, a);



    /* 打印计算结果 */

    InversePrint(L->next);

    printf("\n");

    /* 统计计算结果中0-9出现个数 */

    CountNum(L, num);

    for(i=0; i<10; i++){

        printf("the number of %d is: %d\n", i, num[i]);

        len+=num[i];

    }

    printf("the length of the result is %d\n", len);

    return 0;

}


