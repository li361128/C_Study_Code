/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


#include "stdio.h"    

#include "stdlib.h"   


#include "math.h"  

#include "time.h"


#define OK 1

#define ERROR 0

#define TRUE 1

#define FALSE 0


typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */


typedef char VertexType; /* 顶点类型 */

typedef int EdgeType; /* 边上的权值类型 */


#define MAXSIZE 9 /* 存储空间初始分配量 */

#define MAXEDGE 15

#define MAXVEX 9


typedef struct

{

	VertexType vexs[MAXVEX]; /* 顶点表 */
	
	EdgeType arc[MAXVEX][MAXVEX];/* 邻接矩阵，可看作边表 */
	
	int numVertexes, numEdges; /* 图中当前的顶点数和边数 */

}MGraph;


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

Status DeQueue(Queue* Q, char* e)

{

	if (Q->front == Q->rear)/* 队列空的判断 */
	
		return ERROR;
	
	*e = Q->data[Q->front];/* 将队头元素赋值给e */
	
	Q->front = (Q->front + 1) % MAXSIZE;/* front指针向后移一位置， */
	
	/* 若到最后则转到数组头部 */
	
	return  OK;

}

/* ****************************************************** */



void CreateMGraph(MGraph* G)

{

	int i, j;


	G->numEdges = 15;

	G->numVertexes = 9;


/* 读入顶点信息，建立顶点表 */

	G->vexs[0] = 'A';

	G->vexs[1] = 'B';

	G->vexs[2] = 'C';

	G->vexs[3] = 'D';

	G->vexs[4] = 'E';

	G->vexs[5] = 'F';

	G->vexs[6] = 'G';

	G->vexs[7] = 'H';

	G->vexs[8] = 'I';



	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	
	{
	
		for (j = 0; j < G->numVertexes; j++)
		
		{
		
			G->arc[i][j] = 0;
		
		}
	
	}


	G->arc[0][1] = 1;

	G->arc[0][5] = 1;


	G->arc[1][2] = 1;

	G->arc[1][8] = 1;

	G->arc[1][6] = 1;


	G->arc[2][3] = 1;

	G->arc[2][8] = 1;


	G->arc[3][4] = 1;

	G->arc[3][7] = 1;

	G->arc[3][6] = 1;

	G->arc[3][8] = 1;

	G->arc[4][5] = 1;

	G->arc[4][7] = 1;

	G->arc[5][6] = 1;

	G->arc[6][7] = 1;

	for (i = 0; i < G->numVertexes; i++)	
	{	
		for (j = i; j < G->numVertexes; j++)		
		{		
			G->arc[j][i] = G->arc[i][j];		
		}	
	}
}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void BFSTraverse(MGraph G)
{
   /*请补充代码*/
  int i;
  Queue Q;
  InitQueue(&Q);
  int visit[G.numVertexes];
  for(i = 0; i < G.numVertexes ;i ++)
  {
  	visit[i] = FALSE;
  }
  
  for(i = 0 ;i < G.numVertexes ;i ++)
  {
  	if(!visit[i])
	  {
	  	printf("%d ", G.vexs[i]);
	  	visit[i] = TRUE;
	  	EnQueue(&Q, i);
	  	while(!QueueEmpty(Q))
	  	{
	  		char j;
	  		DeQueue(&Q, &j);
	  		int k = 0;
	  		for(;k < G.numVertexes ;k ++)
			  {
	  				if(G.arc[j][k] != 0 && visit[k] == FALSE)
	  				{
	  					printf("%c ", G.vexs[k]);
	  					visit[k] = TRUE;
	  					EnQueue(&Q, k);
					  }
			  }
		  }
	   } 
  }
}
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


int main(void)

{

	MGraph G;

	CreateMGraph(&G);

	printf("广度遍历：");

	BFSTraverse(G);

	printf("\n");

	return 0;

}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */


