#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#define MAXSIZE 100
#define OVERFLOW -1
#define ERROR 0
#define OK 1

typedef struct
{
    char *base;
    char *top;
    int stackSize;
}SqStack;

typedef struct
{
    char *base;
    int front;
    int rear;
}SqQueue;

void InitStack(SqStack *S)
{
    S->base = (char*)malloc(sizeof (char)*MAXSIZE);
    if(!S->base)
    {
        return;
    }
    S->top = S->base;
    S->stackSize = MAXSIZE;
    return ;
}
void Push(SqStack *S,char e)
{
    if(S->top - S->base == S->stackSize)
    {
        return ;
    }
    *S->top ++= e;
}

void Pop(SqStack *S,char*e)
{
    if(S->top - S->base == 0)
    {
        return;
    }
    *e = *--S->top;
}


void InitQueue(SqQueue *Q)
{
    Q->base = (char *) malloc(MAXSIZE*sizeof (char));
    if(!Q->base)
    {
        return ;
    }
    Q->front = Q->rear = 0;
}

void EnQueue(SqQueue *Q,char e)
{
    if((Q->rear + 1)%MAXSIZE == Q->front)
    {
        printf("队列已满\n");
        return ;
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1 )% MAXSIZE;
}
void DeQueue(SqQueue *Q,char *e)
{
    if(Q->front == Q->rear)
    {
        printf("队列为空\n");
        return ;
    }
    *e = Q->base[Q->front];
    Q->front = (Q->front + 1)%MAXSIZE;
}


int main(int argc, char *argv[])
{
    SqStack S;
    SqQueue Q;
    InitStack(&S);
    InitQueue(&Q);
    char s,c,q;
    while((c = getchar())!= '@')
    {
        Push(&S,c);
        EnQueue(&Q,c);
    }
    while(0 != S.top - S.base)
    {
        Pop(&S,&s);
        DeQueue(&Q,&q);
        if(s != q)
        {
            printf("不是回文字符串\n");
            return 0;
        }
    }
    printf("是回文字符串\n");
    return 0;
}
