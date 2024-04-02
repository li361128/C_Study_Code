#include<stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 2
#define FALSE -2

#define MAXSIZE 100
 
typedef struct 
{
	int data[MAXSIZE];
	int front ;
	int rear;
}SqQueue;

void InitSqQueue(SqQueue *Q)
{

	Q->front = 0;
	Q->rear = 0;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front+ MAXSIZE )%MAXSIZE;
}

void EnQueue(SqQueue *Q,int value)
{
	if(QueueLength(*Q) == MAXSIZE - 1)	return ;
	Q->data[Q->rear] = value;
	Q->rear = (Q->rear + 1)%MAXSIZE;
}

void DeQueue(SqQueue *Q,int *value)
{
	if(Q->front == Q->rear)	return;
	*value = Q->data[Q->front];
	Q->front = (Q->front + 1)%MAXSIZE;
}

void printYanghuisanjiao(int n)
{
	SqQueue Q;
	InitSqQueue(&Q);
	int i = 0,j = 0;
	
	EnQueue(&Q,1);
	
	for(;i < n;i ++)
	{
		int previous = 0;
		for(j = 0;j <= i;j ++)
		{
			int current;
			DeQueue(&Q,&current);
			printf("%4d",current);
			EnQueue(&Q,current + previous);
			previous =current;
		}
		EnQueue(&Q,1);
		printf("\n");
	}
	
}

int main()
{
	int n;
	scanf("%d",&n);
	printYanghuisanjiao(n);
	return 0;
}

