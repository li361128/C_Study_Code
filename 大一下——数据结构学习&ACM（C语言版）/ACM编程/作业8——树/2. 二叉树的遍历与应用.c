#include <stdio.h>

#include <malloc.h>

#include <stdlib.h>

#define OVERFLOW 0

#define OK 1

typedef struct node         //二叉树结点类型的定义

{

    char data;

    struct node *lchild; //定义结点的左孩子指针

    struct node *rchild; //定义结点的右孩子指针

} BinTNode, *BTNode;


BinTNode *CreateBinTree()  //输入二叉树的先序遍历序列，创建二叉链表

{

    BinTNode *t;

    char ch;

    ch = getchar();

    if (ch == '0')             //如果读入0，创建空树

        t = NULL;

    else
    {

        t = (BinTNode *) malloc(sizeof(BinTNode)); //申请根结点*t空间

        if (!t) exit(OVERFLOW);

        t->data = ch;                                  //将结点数据ch放入跟结点的数据域

        t->lchild = CreateBinTree();                        //建左子树

        t->rchild = CreateBinTree();                        //建右子树

    }

    return t;

}


void preorder(BTNode t)   //对二叉树进行先序遍历。提示：打印采用 %3c

{

    if (t != NULL)
    {

        printf("%3c", t->data);  //打印节点数据

        preorder(t->lchild);   //先序遍历左子树

        preorder(t->rchild);   //先序遍历右子树

    }

}


void inorder(BTNode t) //对二叉树进行中序遍历。提示：打印采用 %3c

{

    //★★★请补全代码
    if (t != NULL)
    {

        inorder(t->lchild);   //先序遍历左子树 
        
        printf("%3c", t->data);  //打印节点数据

        inorder(t->rchild);   //先序遍历右子树

    }

}



//二叉树的叶子结点数

int Leaf(BTNode t)
{

    //★★★请补全代码
    if(!t)	return 0;
    if(t->lchild == NULL && NULL == t->rchild)		return 1;
	return Leaf(t->lchild) + Leaf(t->rchild);
}



//二叉树的最大值

int Max(BTNode t)
{

    //★★★请补全代码
    if(!t)	return 0;
    if(t->lchild == NULL && NULL == t->rchild)	return t->data;
    return Max(t->lchild) > Max(t->rchild) ? Max(t->lchild) : Max(t->rchild);

}


    int main()
    {

        BTNode t = NULL;

        //int TreeHeight;

        t = CreateBinTree();

        preorder(t);                             //调用二叉树先序遍历函数

        printf("\n");

        inorder(t);                              //调用二叉树中序遍历函数

        printf("\n");

        printf("%d\n", Leaf(t));

        printf("%c\n", Max(t));


    }
