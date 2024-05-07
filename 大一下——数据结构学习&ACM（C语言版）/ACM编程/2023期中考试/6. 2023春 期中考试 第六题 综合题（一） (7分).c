#define MAXINTSIZE 512 /* 最大整数长度 */

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



/* 用头插法建立单链表 */

Status CreateList(LinkList *L, char *chars)

{

     //★★★请补全代码
    LinkList p = (*L);
	int i = 0;
	for(;chars[i] != '\0';i ++)
	{
		LNode *r;
		r = (LinkList)malloc(sizeof(LNode));
		if(!r)	return ERROR;
		r->data = chars[i] - '0';
		r->next = p->next;
		p->next = r;
		p = r;
	}
	return OK;



}



int ListLength_L(LinkList L){

    LinkList p;

    int i=0;             

    p=L->next;        //p指向第一个结点

    while(p){         //遍历单链表,统计结点数

        i++;

        p=p->next;

    } 

    return i;                             

}// ListLength_L



Status  InversePrint(LinkList p){

   //逆序打印不带头结点的单链表的元素    

   if(!p) return OK;
   
    printf("%d",p->data);

   InversePrint(p->next);

  // printf("%d",p->data);

   return OK;

}// 



int main()

{

    int len;

    char str[MAXINTSIZE+1];

    LinkList L;

    scanf("%s", str);
    
    L = (LinkList)malloc(sizeof(LNode));

    CreateList(&L, str);

    len=ListLength_L(L);

    printf("the length of the integer is %d\n", len);

    InversePrint(L->next);

    printf("\n");

    return 0;

}


