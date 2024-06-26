//编写DFSTraverse函数

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


#include "stdio.h"    

#include "stdlib.h"   


#include "math.h"  

#include "time.h"


#define OK 1

#define ERROR 0

#define TRUE 1

#define FALSE 0


typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */


typedef char VertexType; /* 顶点类型 */

typedef int EdgeType; /* 边上的权值 */


#define MAXSIZE 9 /* 存储空间初始分配量 */

#define MAXEDGE 15

#define MAXVEX 9


typedef struct

{

	VertexType vexs[MAXVEX]; /* 顶点表 */

	EdgeType arc[MAXVEX][MAXVEX];/* 邻接矩阵，可看作边表 */

	int numVertexes, numEdges; /* 图中当前的顶点数和边数 */

}MGraph;


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

void DFSTraverse(MGraph G)
{
   /*请补充代码*/
   int i = 0;
   int visit[G.numVertexes + 1];
   for(i = 0; i < G.numVertexes; i++)
   {
   		visit[i] = FALSE;
	} 
	int stack[MAXVEX];
	int top = -1;
	for(i = 0 ;i < G.numVertexes ;i ++)
	{
		if(visit[i] == FALSE)
		{			
			stack[++top] = i;
			while(top != -1)
			{
				int temp = stack[top--];
				if(visit[temp] == FALSE)
				{
					printf("%c ",G.vexs[temp]);
					visit[temp] = TRUE;
					int k = 0;
					for(k = G.numVertexes - 1; k >= 0 ; k --)
					{
						if(G.arc[temp][k] != 0 && visit[k] == FALSE)
						{
							stack[++top] = k;
						}
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

	printf("深度遍历：");

	DFSTraverse(G);

	printf("\n");

	return 0;

}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
