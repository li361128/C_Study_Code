#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"


typedef int QElement;

//结点类型定义
typedef struct Node
{
    int value;
    struct Node *next;
}QueueNode;

typedef struct Queue
{
    QueueNode *front;//设置队头
    QueueNode *rear;//设置队尾
}Queue;

void InitQueue(Queue *q)
{
    q->front = (QueueNode*)malloc(sizeof(Queue));
    if (NULL == q->front)
    {
        printf("malloc free failed!\n ");
        return;
    }
    q->rear = q->front;
    q->front->next= NULL;//使用带有头节点指针的链队列
}

void EnterQueue(Queue *q, QElement x)
{
	QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
	if(!temp)	
	{
        printf("malloc free failed!\n ");
        return;
    }
	temp->value = x;
	q->rear->next = temp;
	q->rear = q->rear->next; 
}

void DeQueue(Queue *q,QElement *x)
{
	if(q->front == q->rear)	return ;
	*x = q->front->next->value;
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if(!temp)	
	{
        printf("malloc free failed!\n ");
        return;
    }
	temp = q->front;
	q->front = temp->next;
	free(temp); 
}

void GetQueueHead(Queue *q,QElement *x)
{
	if(q->front == q->rear)	return ;
	*x = q->front->next->value;
}

int main(void)
{
    Queue q;
	int QueueHead;
	int DequeValue;
    InitQueue(&q);
    EnterQueue(&q, 1);
	EnterQueue(&q, 2);
	EnterQueue(&q, 3);
	GetQueueHead(&q,&QueueHead);
	printf("队头元素为：%d\n",QueueHead);
	DeQueue(&q,&DequeValue);
	printf("出队元素为：%d\n",DequeValue);

    return 0;
}
