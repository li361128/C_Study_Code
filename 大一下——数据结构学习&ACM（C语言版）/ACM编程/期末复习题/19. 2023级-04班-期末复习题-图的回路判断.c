/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */



#include "stdio.h"    

#include "stdlib.h"  



#include "math.h"  

#include "time.h"



#define OK 1

#define ERROR 0

#define TRUE 1

#define FALSE 0



typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef char VertexType; /* 顶点类型 */

typedef int EdgeType; /* 边上的权值 */


#define MAXSIZE 9 /* 存储空间初始分配量 */

#define MAXEDGE 6

#define MAXVEX 6

int visited[MAXVEX]; /* 访问标志的数组 */ 
int parent[MAXVEX]; /*父链接结点*/


typedef struct

{

VertexType vexs[MAXVEX]; /* 顶点表 */

EdgeType arc[MAXVEX][MAXVEX];/* 邻接矩阵，可看作边表 */

int numVertexes, numEdges; /* 图中当前的顶点数和边数 */

}MGraph;



int count =0;//连通分量的个数，全局变量



void CreateMGraph(MGraph* G)

{

int i, j;



G->numEdges = MAXEDGE;

G->numVertexes = MAXVEX;



/* 读入顶点信息，建立顶点表 */

G->vexs[0] = 'A';

G->vexs[1] = 'B';

G->vexs[2] = 'C';

G->vexs[3] = 'D';

G->vexs[4] = 'E';

G->vexs[5] = 'F';





for (i = 0; i < G->numVertexes; i++)/* 初始化图 */

{

for (j = 0; j < G->numVertexes; j++)

{

G->arc[i][j] = 0;

}

}



G->arc[0][1] = 1;

G->arc[0][4] = 1;

G->arc[0][5] = 1;

G->arc[1][2] = 1;

G->arc[2][3] = 1;

G->arc[3][4] = 1;





for (i = 0; i < G->numVertexes; i++)

{

for (j = i; j < G->numVertexes; j++)

{

G->arc[j][i] = G->arc[i][j];

}

}

}



int LocateVex(MGraph G, VertexType e)

{

// 初始条件:图G存在,u和G中顶点有相同特征

// 操作结果:若G中存在顶点u,则返回该顶点在图中位置;否则返回-1

//补充函数
	
	int i = 0;
	for(;i < G.numVertexes;i ++)
	{
		if(G.vexs[i] == e)	return i;
	 } 
	 return -1;

}


Status FindCycle(MGraph G, int v0) 
{
	int i = 0;
	for(i = 0;i < G.numVertexes;i ++)
	{
		visited[i] = 0;
		parent[i] = 0;
	}
	int stack[MAXSIZE];
	int top = -1;
	
	for(i = 0;i < G.numVertexes;i ++)
	{
		if(visited[i] == 0)
		{
			stack[++top] = i;
			while(top != -1)
			{
				int u = stack[top --];
				visited[u] = 1;
				int k = 0;
				for(;k < G.numVertexes; k++)
				{
					if(G.arc[u][k] != 0)
					{
						if(visited[u] == 0)
						{
							stack[++top];
							parent[k] = u;
						}
						else if(k != parent[u])
							return TRUE;
					}
				}
			}
		}
	}
	return 0;
}

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */



int main(void)

{

MGraph G;

int flag=0;

int i;

CreateMGraph(&G);

for(i=0;i< MAXVEX ;i++)

{

visited[i]=0;

parent[i]=-1;

}

flag=FindCycle(G,0);

if(!flag)

{

printf("图没有回路\n");

}

else

{

printf("图有回路\n");

}

return 0;

}



/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
