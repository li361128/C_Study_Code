/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "stdio.h"

#include "stdlib.h"

#include "string.h"

#define TRUE 1

int visited[4];

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

   VertexNode adjList[4];//有4个VertexNode这种类型的顶点，定义一个数组adjList[4]，每个元素是VertexNode类型

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

visited[k]=0;

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

int LocateVex(GraphAdjList G,char u)

{ // 初始条件: 图G存在,u和G中顶点有相同特征

  // 操作结果: 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1

  int i;

  for(i=0;i < G.numVertexes;i ++)
  {
  		if(G.adjList[i].data == u)	return i;
  }

    return -1;

}

int NextAdjVex(GraphAdjList G,int v,int w)

{ // 初始条件: 图G存在,v是G中某个顶点,w是v的邻接顶点

  // 操作结果: 返回v的(相对于w的)下一个邻接顶点的序号。

  // 若w是v的最后一个邻接点,则返回-1

  EdgeNode *p;

  p=G.adjList[v].firstedge;

  while(p&&p->adjvex!=w)  

  {

  p=p->next;

  }

  if(!p||!p->next)  //没找到w或w是最后一个邻接点

    return -1;

  else   //p->adjvex==w

    return p->next->adjvex;

}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

//补充函数代码

void isConnected(GraphAdjList G, int v1, int v2, int *flag)
{
	if(v1 == v2)	
	{
		*flag = TRUE;
		return ;
	}
	EdgeNode *p;
	p=G.adjList[v1].firstedge;
	while(p)
	{
		int res = NextAdjVex(G, p->adjvex, v2);
		if(res == -1)
			p = p->next;
		else
		{
			*flag = 1;
			return;
		}
	}	
}



/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

int main(void)

{

   GraphAdjList p;

char u1;

char u2;

int v1;

int v2;

int flag=0;

   CreateALGraph(&p);

printf("输入两个顶点:\n");

scanf("%c %c",&u1,&u2);

v1=LocateVex(p,u1);

v2=LocateVex(p,u2);

isConnected(p,v1,v2,&flag);

if(flag)

{

printf("顶点相通\n");

}

else

{

printf("顶点不相通\n");

}

   return 0;

}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
