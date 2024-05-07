#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

typedef int SElemType;

typedef struct StackNode 
{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

void InitStack(LinkStack *S) 
{
    // 补充完整
    *S = (LinkStack)malloc(sizeof(StackNode)) ;
    if(!(*S))	return ;
    (*S)->next = NULL; 
}

int StackEmpty(LinkStack S) 
{
    if (S ->next == NULL) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

void Push(LinkStack *S, SElemType e) 
{
	LinkStack p = *S;	
	LinkStack r;
	r = (LinkStack)malloc(sizeof(StackNode));
	if(!r)	return ;
	r->data = e;
	r->next = p->next;
	p->next = r;
}

int Pop(LinkStack *S, SElemType *e) 
{
    // 补充完整
    if(StackEmpty(*S)) return ERROR;
    LinkStack p = *S;
    LinkStack q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q); 

	return OK; 
}

void Conversion() 
{
    LinkStack S;
    InitStack(&S);
    printf("请输入非负十进制数\n");
    int N;
    N = 1348;
    while (N != 0) 
    {
        int mod = N % 8;
        Push(&S, mod);
        N = N / 8;
    }
    printf("八进制形式为: ");
    int e;
    while (StackEmpty(S) != 1) 
    {
        if(Pop(&S, &e) == OK)
        printf("%d", e);
    }
    printf("\n");
}

int main() 
{
    Conversion();
    return 1;
}

