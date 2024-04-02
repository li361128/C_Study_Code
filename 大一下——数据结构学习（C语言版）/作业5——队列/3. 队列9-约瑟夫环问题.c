#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0
#define MAXSIZE 36 //存储空间的初始分配量 

typedef struct 
{
	int data[MAXSIZE];
	int front;
	int rear;
}SqQueue; 

void InitQueue(SqQueue *Q)
{
	Q->front = Q->rear = 0;
}

int QueueLength(SqQueue Q)
{
	return ((Q.front - Q.rear + MAXSIZE)%MAXSIZE);
}

void EnQueue(SqQueue*Q,int e)
{
	if(QueueLength(*Q) == MAXSIZE)	return ;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1)%MAXSIZE;
}

void DeQueue(SqQueue *Q,int *e)
{
	if(Q->front == Q->rear)	return;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1)%MAXSIZE;
}

void joseph_ring(int n,int m,int k)
{
	SqQueue Q;
	InitQueue(&Q);
	int i =0, e;
	for(i = 0;i < n;i ++)	EnQueue(&Q,i + 1);
	for(i = 0; i< k - 1;i ++)
	{
		int e;
		DeQueue(&Q,&e);
		EnQueue(&Q,e);
	}
	while(QueueLength(Q))
	{
		for(i = 0;i < m - 1;i ++)
		{
		
			DeQueue(&Q,&e);
			EnQueue(&Q,e);
		}
		DeQueue(&Q,&e);
		printf("%d ",e);
	}
	printf("\n");

}

int main(int argc, char *argv[]) 
{
	int m,n,k;
	scanf("%d%d%d",&n,&m,&k);
	joseph_ring(n,m,k);
	return 0;
}
