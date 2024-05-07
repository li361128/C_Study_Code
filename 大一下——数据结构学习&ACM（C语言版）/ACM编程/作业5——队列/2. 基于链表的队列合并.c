#include <stdio.h>  

#include <stdlib.h>  

#include <malloc.h>

#define ERROR 0

#define OK 1

#define TRUE 1

#define FALSE 0



typedef struct {

    char name;    

    int arriveTime;  

} QElemType;



typedef int Status;



typedef struct Qnode {

    QElemType   data;

    struct Qnode* next;

}QNode, * QueuePtr;



typedef struct {

    QueuePtr  front;  //front pointer

    QueuePtr  rear;   //rear pointer

}LinkQueue;



// initialization of linked list based queue

Status InitQueue(LinkQueue* Q) {

    Q->front = (QNode*)malloc(sizeof(QNode));

    if (Q->front == NULL)

        return ERROR;

    Q->rear = Q->front;

    Q->rear->next = NULL;

    return OK;

}



//Test empty queue

Status QueueEmpty(LinkQueue Q) {

    if (Q.front == Q.rear)

        return OK;

    else

        return ERROR;

}



// Get the length of a queue

int QueueLength(LinkQueue Q) {

    QNode* p;

    p = Q.front->next;

    int length = 0;

    for (; p->next != NULL; p = p->next)

        length++;

    return length;

}



// Get front item of a queue

Status GetHead(LinkQueue Q, QElemType* e) {

    if (Q.front == Q.rear)

        return ERROR;

    *e = Q.front->next->data;

    return OK;

}



// Delete an item from the queue

Status DeQueue(LinkQueue *Q, QElemType* e) {

    QNode* p;

    if (Q->front == Q->rear)

        return ERROR;

    p = Q->front->next;

    *e = Q->front->next->data;

    Q->front->next = Q->front->next->next;

    if (p == Q->rear)

        Q->rear = Q->front;

    return OK;

}



// Insert an item into the queue

Status EnQueue(LinkQueue* Q, QElemType e) {

    QNode* p;

    p = (QNode*)malloc(sizeof(QNode));

    if (p == NULL)

        return ERROR;

    p->data = e;

    p->next = NULL;

    Q->rear->next = p;

    Q->rear = Q->rear->next;

    return OK;

}



// Print the elements in a queue

void PrintQueue(LinkQueue Q) {

    QNode* p;

    p = Q.front->next;

    while (p != NULL) {

        printf("(%c,%d)\n", p->data.name, p->data.arriveTime);

        p = p->next;

    }

}



//ºÏ²¢ 

void mergeQueue(LinkQueue *Q1, LinkQueue* Q2, LinkQueue* Q3) 
{
	QElemType e1,e2,e3;
    while(!QueueEmpty(*Q1) && !QueueEmpty(*Q2))
    {
    	GetHead(*Q1,&e1);
    	GetHead(*Q2,&e2);
    	if(e1.arriveTime > e2.arriveTime)	
    	{
    		EnQueue(Q3,e2);
    		DeQueue(Q2,&e2);
		}
    	else 
    	{
    		 EnQueue(Q3,e1);
    		 DeQueue(Q1,&e1);
		}
	}
	while(!QueueEmpty(*Q1))
	{
		GetHead(*Q1,&e1);
		EnQueue(Q3,e1);
		DeQueue(Q1,&e1);
	}
	while(!QueueEmpty(*Q2))
	{
		GetHead(*Q2,&e2);
		EnQueue(Q3,e2);
		DeQueue(Q2,&e2);
	}





}



int main(){

    LinkQueue Q1, Q2, Q3;

    char c;

    int length1, length2;

    QElemType QData;

    InitQueue(&Q1);

    InitQueue(&Q2);

    InitQueue(&Q3);

    scanf("%d", &length1);

    c=getchar();
    int i = 0;

    for (; i <= length1 - 1; i++) {

        scanf("%c%d", &QData.name, &QData.arriveTime);

        EnQueue(&Q1, QData);

        c = getchar();

    }

    scanf("%d", &length2);

    c = getchar();

    for (i = 0; i <= length2 - 1; i++) {

        scanf("%c%d", &QData.name, &QData.arriveTime);

        EnQueue(&Q2, QData);

        c = getchar();

    }

    mergeQueue(&Q1, &Q2, &Q3);

    printf("%d\n", length1 + length2);

    PrintQueue(Q3);

}
