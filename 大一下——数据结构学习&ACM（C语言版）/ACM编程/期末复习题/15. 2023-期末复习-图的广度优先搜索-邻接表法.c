/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


#include "stdio.h"

#include "stdlib.h"


#define OK 1

#define ERROR 0

#define TRUE 1

#define FALSE 0



#define MAXSIZE 8 /* 存储空间初始分配量 */

#define MAXEDGE 9 /* 存储空间初始分配量 */


#define MAXVEX 8


typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */


typedef struct EdgeNode//边表节点

{

    int adjvex;//存储该顶点对应的下标

    struct EdgeNode *next;//指向该顶点的下一个邻接点

}EdgeNode;


typedef struct VertexNode//顶点表结点

{

    char data;//顶点

    EdgeNode *firstedge;//边表头指针

}VertexNode;


typedef struct//图的邻接表存储结构

{

    VertexNode adjList[MAXVEX];//有4个VertexNode这种类型的顶点，定义一个数组adjList[4]，每个元素是VertexNode类型

    int numVertexes,numEdges;//图中顶点数和边数，这里是4,5

}GraphAdjList;


void CreateALGraph(GraphAdjList *p)//无向图的邻接表创建

{

int k;

int i;

int j;

    GraphAdjList *Gp=(GraphAdjList *)malloc(sizeof(GraphAdjList));

    EdgeNode *pe;

	printf("请输入顶点数和边数:\n");

	scanf("%d %d",&(Gp->numVertexes),&(Gp->numEdges));

	printf("请输入顶点数的数据:\n");

	getchar();

    for (k = 0; k < Gp->numVertexes; k++)

{

		scanf("%c",&(Gp->adjList[k].data));

		getchar();

Gp->adjList[k].firstedge = NULL;//将边表头指针指向NULL，即置为0

    }

	printf("请输入边的数据:\n");

for (k = 0; k <  Gp->numEdges; k++)//建立边表

{

		scanf("%d %d",&i,&j);

		getchar();

        pe = (EdgeNode *)malloc(sizeof(EdgeNode));

        pe->adjvex = j;// 邻接序号为j

        pe->next = Gp->adjList[i].firstedge;//将pe的指针指向当前顶点指向的结点

        Gp->adjList[i].firstedge = pe;//将当前顶点的指针指向pe


        pe = (EdgeNode *)malloc(sizeof(EdgeNode));

        pe->adjvex = i;

        pe->next = Gp->adjList[j].firstedge;

        Gp->adjList[j].firstedge = pe;//无序图重复上面步骤

    }

*p=*Gp;

}


/* 用到的队列结构与函数********************************** */


/* 循环队列的顺序存储结构 */

typedef struct

{

	int data[MAXSIZE];
	
	int front;    	/* 头指针 */
	
	int rear;/* 尾指针，若队列不空，指向队列尾元素的下一个位置 */

}Queue;


/* 初始化一个空队列Q */

Status InitQueue(Queue* Q)

{

	Q->front = 0;

	Q->rear = 0;

	return  OK;

}


/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */

Status QueueEmpty(Queue Q)

{

	if (Q.front == Q.rear) /* 队列空的标志 */
	
		return TRUE;
	
	else
		
		return FALSE;
	
}


/* 若队列未满，则插入元素e为Q新的队尾元素 */

Status EnQueue(Queue* Q, char e)

{

	if ((Q->rear + 1) % MAXSIZE == Q->front)/* 队列满的判断 */
	
		return ERROR;

	Q->data[Q->rear] = e;/* 将元素e赋值给队尾 */

	Q->rear = (Q->rear + 1) % MAXSIZE;/* rear指针向后移一位置， */

/* 若到最后则转到数组头部 */
	
	return  OK;

}


/* 若队列不空，则删除Q中队头元素，用e返回其值 */

Status DeQueue(Queue* Q, int* e)

{

	if (Q->front == Q->rear)/* 队列空的判断 */
		
		return ERROR;
	
	*e = Q->data[Q->front];/* 将队头元素赋值给e */
	
	Q->front = (Q->front + 1) % MAXSIZE;/* front指针向后移一位置， */
	
	/* 若到最后则转到数组头部 */
	
	return  OK;

}

/* ****************************************************** */


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void BFSTraverse(GraphAdjList G)
{
   /*请补充代码*/
   int i , j ;
   int visit[MAXVEX] ;
   for(i = 0; i < MAXVEX; i++)
   {
   		visit[i] = FALSE;
   }
   Queue Q;
   InitQueue(&Q);
   for(i = 0; i < G.numVertexes; i ++)
   {
   		if(visit[i] == FALSE)
   		{
   			printf("%c ",G.adjList[j].data);
			visit[j] = TRUE;
   			EnQueue(&Q, i);
			while(!QueueEmpty(Q))
			{
				int j;
				DeQueue(&Q, &j);
				EdgeNode *p = G.adjList[j].firstedge;
                while (p)
                {
                    if (!visit[p->adjvex])
                    {
                        visit[p->adjvex] = TRUE;
                        printf("%c ", G.adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }
                    p = p->next;
                }
							
			}	
		}
   }
   
}
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


int main(void)

{

    GraphAdjList p;

    CreateALGraph(&p);

    BFSTraverse(p);//输出的遍历顺序是ADCB

	printf("\n");

    return 0;

}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */


