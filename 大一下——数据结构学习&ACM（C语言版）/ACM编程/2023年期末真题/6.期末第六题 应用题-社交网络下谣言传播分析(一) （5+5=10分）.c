#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20  //最大顶点数

typedef struct ArcNode
{
    int adjvex;  //该边所连接的顶点的位置（即该顶点的数组下标）
    struct ArcNode *nextarc;  //指向下一条边的指针
    int info;  // 边的权值
} ArcNode;

typedef struct VNode
{
    int data;  //顶点信息
    ArcNode *firstarc;  //指向第一条依附该顶点的边的指针
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph
{
    AdjList vertices;
    int vexnum, arcnum;  //图的当前顶点数和弧数
} ALGraph;

// 建立关系网的邻接表数据存储结构
void CreateUDN(ALGraph *G)
{
    // 请补全以下代码
    scanf("%d %d",&G->vexnum, &G->arcnum);
	int i;
	for(i = 1;i <= G->vexnum ;i ++)
	{
		G->vertices[i].data = i;
		G->vertices[i].firstarc = NULL;	
	}
		
	for(i = 0 ;i < G->arcnum ;i ++)
	{
		int v1, v2,weight;
		getchar();
		scanf("%d %d %d",&v1, &v2, &weight);
		
		ArcNode *p1;
		p1 = (ArcNode*)malloc(sizeof(ArcNode));
		if(!p1)	return ;
		p1->adjvex = v2;
		p1->info = weight;
		p1->nextarc = G->vertices[v1].firstarc;
		G->vertices[v1].firstarc = p1;
		
		ArcNode *p2;
		p2 = (ArcNode*)malloc(sizeof(ArcNode));
		if(!p2)	return;
		p2->adjvex = v1;
		p2->info = weight;
		p2->nextarc = G->vertices[v2].firstarc;
		G->vertices[v2].firstarc = p2;
	 } 

}

/* 统计顶点的边的权值之和 */
/* 输入参数为图和待统计的顶点编号 */
/* 函数返回值为该顶点的边权值之和  */
int VexCount(ALGraph G, int v)
{
    // 请补全以下代码
	ArcNode *p = G.vertices[v].firstarc;
	int sum = 0;
	while(p)
	{
		sum += p->info;
		p = p->nextarc;
	}
	return sum;
}

int main()
{
    ALGraph G;
    int choice;
    static int count = 0;
    CreateUDN(&G);

	int i;
    for(i=0; i<G.vexnum; i++)
    {
        printf("%d ", VexCount(G, i+1));
    }
    printf("\n");
    return 0;
}

