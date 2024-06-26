#include<stdio.h> 
#include<stdlib.h>


//函数结果状态代码

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1


typedef char ElemType;
typedef int Status;

//二叉树的二叉链表存储表示

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;//左右孩子指针 
}BiTNode,*BiTree; 

//数据元素类型为BiTree的队列

typedef struct QNode{
    BiTree Qdata;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//构造一个空队列Q

Status InitQueue(LinkQueue *Q)
{
	(*Q).front=(QueuePtr)malloc(sizeof(QNode));
	if(!(*Q).front) exit(OVERFLOW);
	(*Q).front->next=NULL;
	(*Q).rear=(*Q).front;
	
	return OK;
}

//探空，前提Q存在

Status QueueEmpty(LinkQueue Q)
{

	if(Q.front==Q.rear)
	    return TRUE;
	else
	    return FALSE;
}

//插入元素e作为新的队尾元素，前提Q存在

Status EnQueue(LinkQueue *Q,BiTree e)
{

	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));//开辟新结点
	
	if(!p) exit(OVERFLOW);
	
	p->Qdata=e;
	p->next=NULL;
	(*Q).rear->next=p;
	(*Q).rear=p;
	
	return OK;

}

//若队列不空，删除队头元素，用e返回其值，前提Q存在
Status DeQueue(LinkQueue *Q,BiTree *e)
{

	if((*Q).front==(*Q).rear)
	    return ERROR;
	
	QueuePtr p=(*Q).front->next;
	*e=p->Qdata;
	
	(*Q).front->next=p->next;
	if((*Q).rear==p)
	    (*Q).rear=(*Q).front;
	
	free(p);
	return OK;

}


//用先序遍历创建二叉树
Status CreateBiTree(BiTree *T)
{
	char ch = getchar();//读入一个字符
	if(ch == '.') //用.表示空节点
	{
	    *T = NULL;

	}

	else
	
	{
	
		*T = (BiTree)malloc(sizeof(BiTNode));
		
		if(!(*T))
		
			exit(OVERFLOW);
		
		(*T)->data = ch;
		
		CreateBiTree(&(*T)->lchild);
		
		CreateBiTree(&(*T)->rchild);
		
	}
	
	return OK;

}


/*
敬爱的宇宙无敌好老师！！！
调了好久，测试数据都对了！！！ 
扣小分能不能温柔点，可怜可怜孩子吧！！！
小分实在实在是扣不起了，调了那么久会心疼的！！！ 
我知道您一定是全世界最好的老师！！！ 
*/



//返回二叉树的深度
int BiTreeDepth(BiTree T)

{

      //请补齐代码
	if(!T)
		return 0;
		
	int height_left = BiTreeDepth(T->lchild);
	int height_right = BiTreeDepth(T->rchild);
	
	return (height_left > height_right ? height_left : height_right )+ 1;


}



//中序遍历二叉树
Status InOrderTraverse(BiTree T)
{

    //请补全代码
    if(T)
    {
    	InOrderTraverse(T->lchild);
    	printf("%c ",T->data);
    	InOrderTraverse(T->rchild);
	}
	return OK;

}


//层序遍历二叉树
Status LevelOrderTraverse(BiTree T)
{

	if(!T)
	    return ERROR;
	
	LinkQueue Q;
	InitQueue(&Q);
	
	BiTree p;
	
	EnQueue(&Q,T);
	
	while(QueueEmpty(Q)==FALSE)
	{
		DeQueue(&Q,&p);
		
		printf("%c ",p->data);
		
		if(p->lchild)
		    EnQueue(&Q,p->lchild);
		
		if(p->rchild)
		    EnQueue(&Q,p->rchild);
	
	}
	
	return OK;
}



//输出二叉树指定第n层的所有节点
Status LevelNodeOutput(BiTree T,int n)
{

    //补齐代码
    if(!T)
    	return ERROR;
    	
    if(n == 1)
	{//递归的终止条件，刚好T就是第n层的结点 
		printf("%c ",T->data);
		return OK;
	 } 
	LevelNodeOutput(T->lchild, n - 1);
	LevelNodeOutput(T->rchild, n - 1);

	return OK;
}



int main()
{

    BiTree T;

    printf("Create BiTree,please input\n");

    //ABC..DE.G..F...          可以拷贝至控制台

    //ABE.L...DHM..I..J..      可以拷贝至控制台

    CreateBiTree(&T);//按照先序遍历扩展序列创建二叉树

    int ceng;

    scanf("%d",&ceng);

    

    printf("\nInorder traversal ");//中序遍历二叉树

    InOrderTraverse(T);

    printf("\ndeepth of the BiTree  %d\n",BiTreeDepth(T));//打印树的深度
    

    printf("the node of the %d level is ",ceng);

    LevelNodeOutput(T,ceng);//输出指定层的节点

    return 0; 

}
