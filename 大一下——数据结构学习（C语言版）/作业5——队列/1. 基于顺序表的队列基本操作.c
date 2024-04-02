#include <stdio.h>  

#include <stdlib.h>  

#include <malloc.h>

#define ERROR 0

#define OK 1

#define TRUE 1

#define FALSE 0

typedef int QElemType;  

typedef int Status;

 

// definition of array based queue

#define MAXQSIZE  100   // maximum length

typedef struct {

   QElemType     *base;   //pointer the allocated memory

   int  front;                    //front indicator

   int  rear;                     //rear indicator

}SqQueue; 

 

 

//========================================== 

// initialization of array-based queue

//=========================================== 

Status InitQueue (SqQueue *Q)
{
	Q->base = (QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q->base)
	{
		printf("ERROR");
	 } 
	 Q->front = 0;
	 Q->rear = 0;
	 return OK; 
   

}//InitQueue

 

//========================================

//Test empty queue

//========================================

Status QueueEmpty (SqQueue Q)
{

	return (Q.rear - Q.front + MAXQSIZE)%MAXQSIZE ? 0:1;    

}

 

//===============================================

// Get the length of a queue

//==============================================

int QueueLength (SqQueue Q)
{

	return (Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;                       

}

 

//=====================================

// Get front item of a queue

//====================================

Status GetHead (SqQueue Q, QElemType *e)
{

	if(Q.front != Q.rear)
	{
		*e = Q.base[Q.front];
		return OK;
	 } 
	 return -1;
}

 

//===================================================

// Delete an item from the queue

//====================================================

Status DeQueue(SqQueue *Q,QElemType *e)
{

	if(Q->front == Q->rear)
	{
		return ERROR;
	  }  
	  *e = Q->base[Q->front];
	  Q->front = (Q->front + 1)%MAXQSIZE;
	  return OK;

}

 

//======================================

// Insert an item into the queue

//=======================================

Status EnQueue (SqQueue *Q, QElemType e)
{
	if(QueueLength(*Q) >= MAXQSIZE)
	{
		return ;
	 } 
	 Q->base[Q->rear] = e;
	 Q->rear = (Q->rear + 1)%MAXQSIZE;
	return OK;
}

 

//========================================

//Clear a Queue

//===========================================

Status ClearQueue (SqQueue *Q)
{
	if(!Q->base)	return ERROR;
	free(Q->base);
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

 

//======================================

// Print the elements in a queue

//=======================================

//void PrintQueue (SqQueue S)
//{
//
//	int i = 0;
//	for(;i < QueueLength(S);i ++)
//	{
//		printf("%d ",S.base[i]);
//	}       
//	printf("\n");
//}

void PrintQueue(SqQueue Q) {
    int i = Q.front;
    while (i != Q.rear) {
        printf("%d ", Q.base[i]);
        i = (i + 1) % MAXQSIZE;
    }
    printf("\n");
}
 

int main()  

{  

	SqQueue Q;
	InitQueue(&Q);
	int e,n;
	while(1)
	{
		scanf("%d",&e);
		if(e == -1)	break;
		EnQueue(&Q,e);
	}
	PrintQueue(Q);
	printf("%d\n",QueueLength(Q));
	scanf("%d",&n);
	for(;n > 0;n --)
	{
		DeQueue(&Q,&e);
	}
	
	PrintQueue(Q);
	return OK;


}


