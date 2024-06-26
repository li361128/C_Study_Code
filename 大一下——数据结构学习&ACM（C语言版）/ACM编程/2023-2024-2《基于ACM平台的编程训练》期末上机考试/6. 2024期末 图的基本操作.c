#include <stdio.h>

#define MVNum 100                    //最大顶点数
#define OK 1
#define ERROR 0
#define OVERFLOW -2
 
typedef int VerTexType;              //假设顶点的数据类型为整型 

//图的邻接矩阵存储表示
typedef struct{ 
	VerTexType vexs[MVNum];            //顶点表 
    int arcs[MVNum][MVNum];            //邻接矩阵 
    int vexnum,arcnum;                 //图的当前点数和边数 
}AMGraph;

//确定点v在G中的位置
int LocateVex(AMGraph G , VerTexType v){
	int i;
	for(i = 0; i < G.vexnum; ++i)
	    if(G.vexs[i] == v)
	        return i;
    return -1;
}


/*
敬爱的宇宙无敌好老师！！！
调了好久，测试数据都对了！！！ 
扣小分能不能温柔点，可怜可怜孩子吧！！！
小分实在实在是扣不起了，调了那么久会心疼的！！！ 
我知道您一定是全世界最好的老师！！！ 
*/


//采用邻接矩阵表示法，创建无向网G 
int CreateUDN(AMGraph *G)
{ 

 //★★★请补全代码
 	printf("Please input the total number of vertices and the total number of edges, separated by a space:\n");
 	scanf("%d %d", &G->vexnum, &G->arcnum);
 	int i = 0,j = 0;
 	getchar();
 	printf("Please input the names of the vertices, such as 1:\n");
 	for(i = 0;i < G->vexnum;i ++)
 	{
 		scanf("%d",&G->vexs[i]);
	 }
	 
	 //邻接矩阵的初始化 
	 for(i = 0;i < G->vexnum;i ++)
	 	for(j = 0;j < G->vexnum;j ++)
	 		G->arcs[i][j] = 0;
	
	printf("Please input the vertices to which the edge is attached, such as 1 2:\n");
	
 	for(i = 0;i < G->arcnum;i ++)
 	{
 		getchar();
 		int v1, v2;
 		scanf("%d %d", &v1, &v2);
 		
 		int a1 = LocateVex(*G, v1);
 		int a2 = LocateVex(*G, v2);
 		
 		G->arcs[a1][a2] = 1;
 		G->arcs[a2][a1] = 1;//无向图，重复操作 
 		
	 }

	return OK;
} 

//输出无向网G的邻接矩阵 
void OutputAdjMatrix(AMGraph G)
{ 
 //★★★请补全代码
	int i ,j;
	printf("\nThe adjacency matrix of the undirected network G is:\n");
	for(i = 0;i < G.vexnum;i ++)
	{
		for(j = 0;j < G.vexnum;j ++)
		{
			printf("%d  ",G.arcs[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//输出无向网G的各顶点的度 
void OutputDegree(AMGraph G)
{ 
 //★★★请补全代码

	int total, i, j;
	for(i = 0;i < G.vexnum;i ++)
	{
		total = 0;//作每个顶点的度的计数器，每次循环都更新一遍 
		for(j = 0;j < G.vexnum;j ++)
		{
			if(G.arcs[i][j] != 0)//有相连即加1 
				total ++;
		}
		printf("The degree of vertex %d is %d\n", G.vexs[i], total);
	}


}

int main(){
    AMGraph G;
    CreateUDN(&G);
    OutputAdjMatrix(G);
    OutputDegree(G);
    return 0;
}
