#include <stdio.h>

#include <stdlib.h>



typedef int Status;

#define OK 1

#define ERROR 0

#define OVERFLOW -2



//链队列的存储结构

typedef struct QNode {

     int data;

     struct QNode *next;

} QNode, *QueuePtr;



typedef struct {

     QueuePtr front; //队头指针

     QueuePtr rear; //队尾指针

     int QLength; //队长 

} LinkQueue;



//链队列的初始化

Status InitQueue(LinkQueue *Q) {

     Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));

     Q->front->next = NULL;

     Q->QLength = 0; 

     return OK;

}



//插入元素e为链队列Q的新的队尾元素

Status EnQueue(LinkQueue *Q, int e) {

     QueuePtr p;

     p = (QueuePtr) malloc(sizeof(QNode));

     p->data = e;

     p->next = NULL;

     Q->rear->next = p;

     Q->rear = p;

     Q->QLength++;

     return OK;

}



//删除链队列Q的队头元素，用e返回其值

Status DeQueue(LinkQueue *Q, int *e) { 

    //请补全代码
    if(Q->QLength == 0)	return ERROR;
    

	 QueuePtr p = Q->front->next;
	*e = p->data;  
	 Q->front->next = p->next;
	 free(p);
	 Q->QLength --;
	 return OK;






}



//返回链队列Q的队头元素，不修改队头指针

int GetHead(LinkQueue Q) {

     if ((Q.front != Q.rear) && (Q.QLength != 0))

          return Q.front->next->data;

}





int main() {

    //请补全代码
    LinkQueue Q;
    InitQueue(&Q);
    
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i = 0;i < n;i ++)
    {
    	scanf("%d",&arr[i]); 
    	EnQueue(&Q,arr[i]);
	}
	if(n == 1)	printf("%d",arr[i]);
	for(i = 0;i <n;i ++)
	{
		int temp;
		DeQueue(&Q,&temp);
		if(Q.QLength == 0 || Q.rear->data != temp)	EnQueue(&Q,temp);
	}
		
	QueuePtr p = Q.front->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}

}
