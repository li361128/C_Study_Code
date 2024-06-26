#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20  //最大顶点数
#define TH 4  // 信任度阈值
#define OVERFLOW -1
#define ERROR 0
#define OK 1

typedef int Status;
typedef int QElemType;
// 邻接矩阵
typedef struct ArcCell
{
    unsigned int weight;  //权值
}AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

// 无向网
typedef struct MGraph
{
    AdjMatrix arcs;  //邻接矩阵
    int vexnum, arcnum;  //顶点数，弧数
}MGraph;

// 链队列结点
typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
   QueuePtr front,rear; /* 队头、队尾指针 */
}LinkQueue;

int visited[MAX_VERTEX_NUM]; // 顶点是否被访问过
int credit[MAX_VERTEX_NUM]; // 顶点的信用值
int times[MAX_VERTEX_NUM]; // 顶点收到谣言时间

Status InitQueue(LinkQueue *Q)
{ /* 构造一个空队列Q */
    (*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(QNode));
    if(!(*Q).front)
        exit(OVERFLOW);
    (*Q).front->next=NULL;
    return OK;
}

Status QueueEmpty(LinkQueue Q)
{ /* 若Q为空队列,则返回TRUE,否则返回FALSE */
    return(Q.front==Q.rear);
}

Status EnQueue(LinkQueue *Q,QElemType e)
{ /* 插入元素e为Q的新的队尾元素 */
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) /* 存储分配失败 */
        exit(OVERFLOW);
    p->data=e;
    p->next=NULL;
    (*Q).rear->next=p;
    (*Q).rear=p;
    return OK;
}

Status DeQueue(LinkQueue *Q,QElemType *e)
{ /* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
    QueuePtr p;
    if((*Q).front==(*Q).rear)
        return ERROR;
    p=(*Q).front->next;
    *e=p->data;
    (*Q).front->next=p->next;
    if((*Q).rear==p)
        (*Q).rear=(*Q).front;
    free(p);
    return OK;
}

/* 建立社交网络 */
void CreateUDN(MGraph *G)
{
    scanf("%d %d",&G->vexnum, &G->arcnum);
    int i, j;
    //初始化邻接矩阵 
    for(i = 0; i < G->vexnum; i++)
    {
        for(j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].weight = 0;
        }
    }
    
    for(i = 0; i < G->arcnum ;i ++)
    {
        int v1, v2, weight;
        getchar();
        scanf("%d %d %d",&v1, &v2, &weight);
        G->arcs[v1 - 1][v2 - 1].weight = weight;
        G->arcs[v2 - 1][v1 - 1].weight = weight;
    }
}

/* 广度优先搜索网络，计算谣言传播路径、信任度、传播时间 */
/* 参数：邻接矩阵图；传播谣言的顶点编号 */
void BFSGraph(MGraph G, int v)
{
    int i, j;
    LinkQueue Q; // 辅助队列
    InitQueue(&Q);
    for(i = 0; i < G.vexnum; i++)
    {
        visited[i] = 0;
        credit[i] = 0;
        times[i] = 0; // 初始化为-1表示未传播到
    }
    visited[v] = 1;
    credit[v] = 0;
    times[v] = 1;
    printf("%d ", v + 1);
    EnQueue(&Q, v);

    while(!QueueEmpty(Q))
    {
        int u;
        DeQueue(&Q, &u);

        for(j = 1; j < G.vexnum; j++)
        {
            if(G.arcs[u][j].weight != 0 && !visited[j])
            {
                credit[j] += G.arcs[u][j].weight;
                
                if (!visited[j] && credit[j] >= TH)
                {
                    visited[j] = 1;
                    times[j] = times[u] + 1;
                    EnQueue(&Q, j);
                    printf("%d ", j + 1);
                }
            }
        }
    }
}

int main()
{
    MGraph G;
    int i,j;
    /* 生成网络 */
    CreateUDN(&G);
    /* 输出邻接矩阵 */
    for(i=0; i< G.vexnum; i++){
        for(j=0; j< G.vexnum; j++)
            printf("%d ", G.arcs[i][j].weight);
        printf("\n");
    }
    /* 广度优先遍历遍历网络 */
    BFSGraph(G, 0);
	printf("\n");
    /* 输出各顶点的谣言信任度 */
    for(i = 0; i< G.vexnum; i++)
    {
        printf("%d ", credit[i]);
    }
    printf("\n");
    /* 输出各顶点的谣言传播时间 */
    for(i = 0; i< G.vexnum; i++)
    {
        printf("%d ", times[i]);
    }
    printf("\n");
    return 0;
}

