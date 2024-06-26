#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define VERTEX_NUM 12	 // 顶点数量
#define MAX_EDGES 21	//最大边数量 

//结构体定义边 
struct Edge
{
	int from, to, weight;
};

//给定的边及权重 
struct Edge edges[MAX_EDGES]  
 = { 
    {1, 2, 9}, {1, 3, 7}, {1, 4, 3}, {1, 5, 2},
    {2, 6, 4}, {2, 7, 2}, {2, 8, 1}, {3, 6, 2}, {3, 7, 7},
    {4, 8, 11}, {5, 7, 11}, {5, 8, 8}, {6, 9, 6}, {6, 10, 5},
    {7, 9, 4}, {7, 10, 3}, {8, 10, 5}, {8, 11, 6}, {9, 12, 4},
    {10, 12, 2}, {11, 12, 5}
};


int main(int argc, char *argv[]) 
{
	int stages, i, j, u, k, v;
	scanf("%d", &stages);
	
	int stage_nodes[stages][VERTEX_NUM];
	int stage_sizes[stages];//每个阶段的结点数量 
	
	for(i = 0; i < stages; i ++)
	{
		int node;
		stage_sizes[i] = 0;
		while(scanf("%d", &node) == 1)
		{
			stage_nodes[i][stage_sizes[i] ++] = node;
			if(getchar() == '\n')	break;
		 } 
	}
	
	int dist[VERTEX_NUM + 1];
	int path[VERTEX_NUM + 1];
	
	for(i = 0; i <= VERTEX_NUM; i ++)
	{
		dist[i] = INT_MAX;
		path[i] = -1;
	}
	
	dist[1] = 0;//源点到自己的距离为0
	
	for(i = 0;i < stages - 1; i ++)
	{
		for(j = 0; j < stage_sizes[i]; j ++)
		{
			int u = stage_nodes[i][j];
			for(k = 0; k < MAX_EDGES; k ++)
			{
				if(edges[k].from == u)
				{
					int v = edges[k].to;
					if(dist[u] != INT_MAX && dist[u] + edges[k].weight < dist[v])
					{
						dist[v] = dist[u] + edges[k].weight;
						path[v] = u;
					}
				}
			}
		}
	 } 
	 
	int target = 12;
	printf("%d\n", dist[12]);
    int shortest_path[VERTEX_NUM];
    int shortest_path_length = 0;

    for (v = target; v != -1; v = path[v]) 
	{
        shortest_path[shortest_path_length++] = v;
    }

    for (i = shortest_path_length - 1; i >= 0; --i) 
	{
        printf("%d ", shortest_path[i]);
    }
    printf("\n");

    return 0;
}
