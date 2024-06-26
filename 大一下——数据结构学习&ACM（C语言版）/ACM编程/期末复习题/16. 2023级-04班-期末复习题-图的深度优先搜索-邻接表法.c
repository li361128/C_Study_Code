/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */



#include "stdio.h"

#include "stdlib.h"



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



/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void DFSTraverse(GraphAdjList G)
{
   /*请补充代码*/
   int stack[G.numVertexes];
   int top = -1;
   int visit[G.numVertexes];
   int i;
   for(i = 0 ;i <G.numVertexes ;i ++)
   {
   		visit[i] = 0;
   }
   for(i = 0; i < G.numVertexes ;i ++)	
   {
   		if(visit[i] == 0){
   			printf("%c ", G.adjList[i].data);
   			visit[i] = 1;
   			stack[++top] = i;
   			while(top != -1){
   				int u = stack[top --];
   				EdgeNode *p = G.adjList[u].firstedge;
				if(visit[p->adjvex] == 0){
					printf("%c ", G.adjList[p->adjvex].data);
					visit[p->adjvex] = 1;
					stack[++top] = p->adjvex;
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

   DFSTraverse(p);//输出的遍历顺序是ADCB
	
	printf("\n");

   return 0;

}



/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
