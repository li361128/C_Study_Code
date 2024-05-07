#include <stdio.h>

#include <stdlib.h>

#define OK 1

#define ERROR 0

#define OVERFLOW 0



typedef char ElemType;

typedef int Status;

typedef struct QNode

{

    ElemType data;

    struct QNode *next;

}QNode,*queuePtr;   



typedef struct

{

    queuePtr front; //指向链队列的头

    queuePtr rear;  //指向链队列的尾 

}LinkQueue;



//队列初始化

Status InitQueue(LinkQueue *q)

{

   q->front=q->rear=(queuePtr)malloc(sizeof(QNode));  //创建头节点 头指针指向头节点

   if(!q->front)  //创建失败

   {

       return ERROR;

   }

   q->front->next=NULL;

   return OK;

}



//判断队列是否为空

Status QueueEmpty(LinkQueue Q)

{

    if(Q.front==Q.rear)

        return OK;

    else

        return ERROR;

}// QueueEmpty



int QueueLength (LinkQueue Q)

{

    int i;

    queuePtr p;

    p = Q.front->next;   //p指向队头

    i=1;

    while(p!=Q.rear)  //遍历链队列,统计结点数

	{

        i++;

        p=p->next;

    }

    return i;

}// QueueLength



//获得队首元素

Status GetHead(LinkQueue q,ElemType *e)

{

    if(q.front == q.rear)

        return ERROR;

    *e = q.front->next->data;

    return OK;

}



//入队

Status EnQueue(LinkQueue *q,ElemType e)

{

    queuePtr p=(queuePtr)malloc(sizeof(QNode)); //为新元素分配空间

    if(!p) return ERROR; 

    p->data=e;

    p->next=NULL;

    q->rear->next=p; //为尾指针的next重新赋值 将元素插入表尾

    q->rear=p;  //重新定位尾指针

    return OK;

}



//删除元素

Status DeQueue(LinkQueue *q,ElemType *e)

{

    if(q->front == q->rear) return ERROR; //此时队列为空

    queuePtr p = q->front->next;  

    *e=p->data;  //删除是队首元素

    q->front->next=p->next;

    if(q->rear == p)

        q->rear=q->front;

    free(p);

    return OK;

}



//清空链队列，如果成功，返回OK，否则返回ERROR

Status ClearQueue (LinkQueue *Q)

{

	//★★★请补全代码
	if(!Q->front)	return ERROR;
	free(Q->front);
	Q->front = Q->rear = 0;
	return OK; 







}// ClearQueue



//输出队列

Status PrintQueue(LinkQueue q)

{

    queuePtr p;

    p = q.front->next;

    while(p)

    {

        printf("%c ",p->data);

        p=p->next;

    }

    return OK;

}



//解密游戏

void DecryptGame(LinkQueue *Q)

{

	//★★★请补全代码
	LinkQueue S;
	InitQueue(&S);
	
	while(!QueueEmpty(*Q))
	{
		char temp;
		DeQueue(Q,&temp);
		EnQueue(&S,temp);
		if(!QueueEmpty(*Q))
		{
			DeQueue(Q,&temp);
			EnQueue(Q,temp);
		}
	} 

	PrintQueue(S);

 



}



int main()

{

    LinkQueue Q;

    InitQueue(&Q);

    int i;

    char a;

    for(i=0;i<10;i++)

    {

        scanf("%c",&a);

        EnQueue(&Q,a);

    }

    DecryptGame(&Q);

    printf("\n");

    ClearQueue(&Q);

    return 0;

}
