#include<stdio.h>

#define MAX_VERTEX_NUM 100

typedef int VertexType;
typedef int AdjMatrix;
typedef int VRType;

typedef struct
{
	AdjMatrix arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	VertexType vexs[MAX_VERTEX_NUM];
	int vexnum, arcnum;
}AMGraph;

void CreateUDN(AMGraph *G)
{
	scanf("%d %d",&G->vexnum, &G->arcnum);
	int i, j;
	for(i = 1;i <= G->arcnum; i ++)
		for(j = 1; j <= G->vexnum; j ++)
		{
			if (i == j) 
            {
                G->arcs[i][j] = 0;  // 自环边权值为0
            } 
            else 
			{
                G->arcs[i][j] = 19191911;  // 其他边初始为无穷大
            }
		}
			
	for(j = 0; j < G->arcnum; j ++)
	{
		int a1, a2, w;
		getchar();
		scanf("%d %d %d", &a1,&a2, &w);
		G->arcs[a1][a2] = w;
		G->arcs[a2][a1] = w;	
	}	
	
//	for(i = 1;i <= G->vexnum; i ++)
//	{
//		for(j = 1; j <= G->vexnum; j ++)
//			printf("%d\t",G->arcs[i][j]);
//		printf("\n");
//	}
}

typedef struct
{
	int adjvex;
	VRType lowcost;
}EdgeNode;

EdgeNode closedge[MAX_VERTEX_NUM];

int MiniSpanTree_Prim(AMGraph G)
{	
	int i, j;
	for(i = 2;i <= G.vexnum;i ++)
	{
		closedge[i].adjvex = 1;
		closedge[i].lowcost = G.arcs[1][i];
	}
	closedge[1].lowcost = 0;
	
	int totalweight = 0;
	
	for(i = 2;i <= G.vexnum;i ++)
	{
		VRType min = 1999999;
		int min_Index = -1;
		for(j = 1;j <= G.vexnum; j++)
		{
			if(closedge[j].lowcost != 0 && closedge[j].lowcost < min)
			{
				min = closedge[j].lowcost;
				min_Index = j;
			}
		}
		if(min_Index == -1)	
		{
			printf("ERROR\n");
			return -1;
		}
	
		totalweight += closedge[min_Index].lowcost;
		closedge[min_Index].lowcost = 0;
		
		for(j = 1;j <= G.vexnum; j ++)
		{
			if(G.arcs[min_Index][j] < closedge[j].lowcost && closedge[j].lowcost != 0)
			{
				closedge[j].adjvex = min_Index;
				closedge[j].lowcost = G.arcs[min_Index][j];
			}
		}
	}
	return totalweight;	
}

int main()
{
	AMGraph G;
	
	CreateUDN(&G);
	
	printf("%d",MiniSpanTree_Prim(G));
	
	return 0;
}
