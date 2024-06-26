#include <stdio.h>

#include <stdlib.h>

#define max_vertex_num 100 //最多顶点个数
#define OK 1
#define ERROR -1

typedef char VertexData;

typedef int AdjType ;

typedef int OtherInfo ;

typedef struct ArcNode

{

       AdjType adj; //对于无权图 用1表示相邻 0表示不相邻 ；对于带权图，则为权值类型

    OtherInfo info;

} ArcNode;

typedef struct

{

  VertexData vertex[max_vertex_num]; //定义存储顶点的数组

  ArcNode arcs[max_vertex_num][max_vertex_num];//定义邻接矩阵

  int vexnum, arcnum; //定义顶点的个数和边的个数

} AdjMatrix;   //邻接矩阵的结构体

 

int LocateVertex(AdjMatrix  *G,VertexData v)  //求顶点的位置

{

       int j=-1,k,i;

       for(k=0;k<G->vexnum;k++)
       {
       		if(G->vertex[k] == v)	return k;
	   }

       return (j);

}

 

void CreateMatrix(AdjMatrix *G) //用邻接矩阵创建无向图

{

       int i,k,j;

       char v1,v2;

       printf("用邻接矩阵来创建图\n请输入图的顶点个数和弧数\n") ;

       scanf("%d%d",&G->vexnum,&G->arcnum);

  		for(i = 0;i < G->vexnum;i ++)
  		{
  			for(j = 0;j < G->vexnum; j ++)
  			{
  				G->arcs[i][j].adj = 0; 
			  }
		  }

       printf("请用一行输入图的各个顶点,不用逗号隔开\n");

       getchar();

       for(i=0;i<G->vexnum;i++)

              scanf("%c",&G->vertex[i]); //输入图的各个顶点

       printf("请用一行输入图中所有两顶点之间的弧，例如，a,b b,c b,d\n");

       for(k=0;k<G->arcnum;k++)

       {

              getchar();

              scanf("%c,%c",&v1,&v2);
              
              int a1 = LocateVertex(G, v1);
              int a2 = LocateVertex(G, v2);
              
              if(a1 == -1 || a2 == -1)	return;

			G->arcs[a1][a2].adj = 1;
			G->arcs[a2][a1].adj = 1;
       }

 

}

 

void print(AdjMatrix *G)  //打印邻接矩阵建立的图

{

    int i,j;

     printf("打印出用邻接矩阵创建的无向图\n");

       for(i=0;i<G->vexnum;i++)

    {

        for(j=0;j<G->vexnum;j++)

            printf("%d ",G->arcs[i][j].adj);

            printf("\n");

    }

}

 

 

 

int main()

{

       AdjMatrix G;

       CreateMatrix(&G);

       print(&G);

       return 0;

}


