#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef int QElemType ;
typedef int Status;

#define ERROR 0
#define OK 1
#define MAXSIZE 100

typedef struct
{
    QElemType *base;
    int front;
    int rear;
}SqQueue;

void InitQueue(SqQueue *Q)
{
    Q->base = (int*) malloc(sizeof (int)*MAXSIZE);
    if(!Q->base)
    {
        return ;
    }
    Q->front = 0 ;
	Q->rear = 0;
}

int QueueLength(SqQueue Q)
{
    return ((Q.rear - Q.front + MAXSIZE) % MAXSIZE);
}

void EnQueue(SqQueue *Q,QElemType e)
{
    if((Q->rear + 1) %MAXSIZE == Q->front)
    {
        return ;
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1)%MAXSIZE;
}

void DeQueue(SqQueue *Q,QElemType *e)
{
    if(Q->front == Q->rear)
    {
        return;
    }
    *e = Q->base[Q->front];
    Q->front = (Q->front - 1)%MAXSIZE;
}


void SeeDoctor()
{
    SqQueue Q;
    int n;
    InitQueue(&Q);
    int flag = 1;
    while(flag)
    {
    	char ch;
        printf("请输入命令\n");
        scanf("%c",&ch);
        getchar();
        switch(ch)
        {
            case 'a' :
	            {
	                printf("病例号：\n");
	                scanf("%d",&n);
	                getchar();
	                EnQueue(&Q,n);
	                break;
	            }
            case 'n':
            {
                if(QueueLength(Q) != 0)
                {
                    DeQueue(&Q,&n);
                    printf("病历号为%d的病人就诊\n",n);
                }
                else
                {
                    printf("无病人等待就诊\n");
                }
                break;
            }
            case 'q':
            {
                printf("今天停止挂号，下列病人依次就诊\n");
                while(QueueLength(Q) == 0)
                {
                    DeQueue(&Q,&n);
                    printf("%d",n);
                }
                flag = 0;
                break;
            }
            default:
                break;
        }
    }
}

int main()
{
    SeeDoctor();
    return 0;
}
