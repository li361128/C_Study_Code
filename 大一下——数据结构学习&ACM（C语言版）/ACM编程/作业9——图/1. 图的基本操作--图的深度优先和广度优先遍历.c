//
// Created by lct2023 on 2024/5/26.
//
#include <stdio.h>

#include <stdlib.h>

#define max_vertex_num 100 //最多顶点个数

typedef char VertexData;

typedef int AdjType;

typedef int OtherInfo;

int visisted[max_vertex_num] = {0}; //供深度优先遍历使用

int visisted1[max_vertex_num] = {0};//供广度优先遍历使用


typedef struct Node
{

    int adjvex;  //定义该弧指向顶点的位置

    struct Node *nextarc; //定义下一条弧上网指针

} Node;


typedef struct VVertexNode
{

    char data; //定义顶点的数据

    Node *firstarc;  //定义该顶点第一条弧的指针

} VertexNode[max_vertex_num];


typedef struct
{

    VertexNode vertex;
	int vexnum, arcnum;

} AdjList;  //定义邻接表



int LocateVertex(AdjList *G, VertexData v)  //求顶点的位置

{

    int j = -1, k, i;

    for (k = 0; k < G->vexnum; k++)
    {
    	if(G->vertex[k].data == v)	return k;
	}

    return (j);

}


void CreateList(AdjList *G) //用邻接表创建无向图

{

    int i, j, k, weight;

    char v1, v2;

    printf("用邻接表来创建图\n请输入图的顶点个数和弧数\n");

    scanf("%d%d", &G->vexnum, &G->arcnum);

    printf("请用一行输入图的各个顶点,不用逗号隔开\n");

    getchar();

    for (i = 0; i < G->vexnum; i++)
    {

        scanf("%c", &G->vertex[i].data); //输入图的各个顶点

        G->vertex[i].firstarc = NULL;

    }

    printf("请用一行输入图中所有两顶点之间的弧，例如，a,b b,c b,d\n");

    int a1, a2;

    for (i = 0; i < G->arcnum; i++)
    {

        getchar();

        scanf("%c,%c", &v1, &v2);

        a1 = LocateVertex(G, v1);
        a2 = LocateVertex(G, v2);
        if(a1 == -1 || a2 == -1)	return ;
        
        Node* p1 = (Node*)malloc(sizeof(Node));
        p1->adjvex = a2;
        p1->nextarc = G->vertex[a1].firstarc;
        G->vertex[a1].firstarc = p1;
        
        Node* p2 = (Node*)malloc(sizeof(Node));
		p2->adjvex = a1;
		p2->nextarc = G->vertex[a2].firstarc;
		G->vertex[a2].firstarc = p2; 

    }


}


void print(AdjList *G)  //打印邻接表建立的图

{

    int i;

    printf("打印出用邻接表创建的无向图\n");

    for (i = 0; i < G->vexnum; i++)
    {

        printf("%c---->", G->vertex[i].data);

        Node *t;

        t = G->vertex[i].firstarc;

        while (t != NULL)
        {

            printf(" %c ", G->vertex[t->adjvex].data);

            t = t->nextarc;

        }

        printf("\n");

    }

}


void DFS(AdjList *g, int i)
{//单个节点开始进行深度优先遍历

    Node *t;

    printf("%c", g->vertex[i].data);

    visisted[i] = 1;

    t = g->vertex[i].firstarc;

    while (t)
    {

        int w = t->adjvex;
        if(!visisted[w])
        	DFS(g, w);
        t = t->nextarc;

    }

}


//void BFS(AdjList *g, int i)
//{//单个节点开始进行广度优先遍历
//
//    int q[max_vertex_num];//用于模拟访问过结点的队列
//
//    int front, rear;//front为队列的头部，rear为队列的尾部
//
//    int temp;//该变量用于接受出队的元素
//
//    front = 0;
//
//    rear = 0;
//
//    printf("%c", g->vertex[i].data);
//
//    visisted1[i] = 1;
//
//    q[rear++] = i;//模拟入队
//
//    Node *p;
//
//    while (rear > front)
//    {
//
//        temp = q[front++];//模拟出队
//
//        p = g->vertex[temp].firstarc;
//
//        if(!visisted1[temp])
//        {
//        	visisted1[temp] = 1;
//        	printf("%c", g->vertex[temp].data);
//        	q[rear++] = temp;//模拟入队
//		}
//
//    }
//}

void BFS(AdjList *g, int i)
{
    int q[max_vertex_num]; // 用于模拟访问过结点的队列
    int front = 0, rear = 0; // front为队列的头部，rear为队列的尾部

    printf("%c", g->vertex[i].data);
    visisted1[i] = 1;
    q[rear++] = i; // 模拟入队

    Node *p;

    while (rear > front)
    {
        int temp = q[front++]; // 模拟出队
        p = g->vertex[temp].firstarc;

        while (p != NULL)
        {
            int neighbor = p->adjvex;
            if (!visisted1[neighbor])
            {
                printf("%c", g->vertex[neighbor].data);
                visisted1[neighbor] = 1;
                q[rear++] = neighbor; // 模拟入队
            }
            p = p->nextarc;
        }
    }
}


int main()
{

    AdjList GG;

    CreateList(&GG);

    print(&GG);

    printf("以A开始的深度优先遍历(DFS):\n");

    DFS(&GG, 0);

    printf("\n以A开始的广度优先遍历(BFS):\n");

    BFS(&GG, 0);

    printf("\n");

    return 0;

}
