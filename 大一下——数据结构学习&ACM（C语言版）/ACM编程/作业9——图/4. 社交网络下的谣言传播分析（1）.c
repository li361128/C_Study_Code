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
	int i, w, a1, a2;
	for(i = 1;i <= G->vexnum;i ++)
		G->vertices[i].firstarc = NULL;
	
	for(i = 1; i <= G->arcnum ;i ++)
	{
		getchar();
		scanf("%d %d %d",&a1, &a2, &w);
		if(a1 <= 0 || a1 > G->vexnum || a2 <= 0 || a2 > G->vexnum)
			return;
		
		ArcNode *p1 = (ArcNode*)malloc(sizeof(ArcNode));
		p1->adjvex = a2;
		p1->info = w;
		p1->nextarc = G->vertices[a1].firstarc;
		G->vertices[a1].firstarc = p1->nextarc;
		
		ArcNode *p2 = (ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex = a1;
		p2->info = w;
		p2->nextarc = G->vertices[a2].firstarc;
		G->vertices[a2].firstarc = p2->nextarc;
		
	}
}

/* 统计顶点的边的权值之和 */
/* 输入参数为图和待统计的顶点编号 */
/* 函数返回值为该顶点的边权值之和  */
int VexCount(ALGraph G, int v)
{
    // 请补全以下代码
    int sum = 0;
    ArcNode *p = G.vertices[v].firstarc;
    while (p != NULL) 
	{
        sum += p->info;
        p = p->nextarc;
    }
    return sum;
    

}

int main()
{
    ALGraph G;
    int choice, i;
    static int count = 0;
    CreateUDN(&G);

    for(i=0; i<G.vexnum; i++)
    {
        printf("%d ", VexCount(G, i+1));
    }
    printf("\n");
    return 0;
}

