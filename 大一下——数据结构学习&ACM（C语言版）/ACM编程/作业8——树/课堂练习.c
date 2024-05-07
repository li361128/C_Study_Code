//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define OK 1
//#define ERROR 0
//#define OVERFLOW -2
//
//typedef char DataType;
//
//// Define the structure of a binary tree node
//typedef struct TreeNode 
//{
//    DataType data;
//    struct TreeNode *lchild;
//    struct TreeNode *rchild;
//} LinkBiTree;
//
//// Function to perform postorder traversal and print the binary tree
//void PostOrderTraverse(LinkBiTree* T) 
//{
//    if (T) 
//	{
//        PostOrderTraverse(T->lchild); // Traverse left subtree
//        PostOrderTraverse(T->rchild); // Traverse right subtree
//        printf("%c ", T->data);       // Print root
//    }
//}
//
//// Function to create a binary tree from given preorder and inorder sequences
//void CreateBiTree(LinkBiTree **T, char *PreStr, char *InStr, int L1, int R1, int L2, int R2) 
//{
//    if (L1 > R1 || L2 > R2) // Base case: empty subtree
//        *T = NULL;
//    else 
//	{
//        (*T) = (LinkBiTree *)malloc(sizeof(LinkBiTree)); // Allocate memory for the new node
//        if (!(*T))    exit(OVERFLOW);
//
//        (*T)->data = PreStr[L1]; // Set the data of the node
//
//        int root;
//        for (root = L2; root <= R2; root++) 
//		{
//            if (InStr[root] == PreStr[L1])     break;
//        }
//        printf("Root node '%c' is at index %d in the inorder sequence.\n", PreStr[L1], root);
//        
//        if (root - L2 != 0) // If there are left children
//            CreateBiTree(&(*T)->lchild, PreStr, InStr, L1 + 1, L1 + root - L2, L2, root - 1);
//        else
//            (*T)->lchild = NULL;
//
//        if (R2 - root != 0) // If there are right children
//            CreateBiTree(&(*T)->rchild, PreStr, InStr, R1 - R2 + root + 1, R1, root + 1, R2);
//        else
//            (*T)->rchild = NULL;
//    }
//}
//
//int main() {
//    char PreStr[30], InStr[30];
//    printf("Enter the preorder sequence: ");
//    scanf("%s", PreStr);
//    printf("Enter the inorder sequence: ");
//    scanf("%s", InStr);
//
//    int len1 = strlen(PreStr);
//    int len2 = strlen(InStr);
//
//    LinkBiTree *T = NULL;
//    CreateBiTree(&T, PreStr, InStr, 0, len1 - 1, 0, len2 - 1);
//
//    printf("Postorder traversal of the binary tree: ");
//    PostOrderTraverse(T);
//    printf("\n");
//
//    return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//
//#define OK 1
//#define ERROR 0
//
//// Define the structure of a binary tree node
//typedef struct BiTNode {
//    char data;
//    struct BiTNode *lchild;
//    struct BiTNode *rchild;
//} BiTNode, *BiTree;
//
//// Function to create a binary tree
//int CreateBiTree(BiTree *T) {
//    char ch;
//    scanf("%c", &ch);
//    getchar(); // Consume the newline character
//
//    if (ch == '#') // Assuming '#' represents empty node
//        *T = NULL;
//    else {
//        *T = (BiTree)malloc(sizeof(BiTNode)); // Allocate memory for the new node
//        if (!*T) // Check if memory allocation failed
//            exit(OVERFLOW);
//
//        (*T)->data = ch; // Set the data of the node
//
//        // Recursively create left and right subtrees
//        if (CreateBiTree(&((*T)->lchild)) == ERROR)
//            return ERROR;
//        if (CreateBiTree(&((*T)->rchild)) == ERROR)
//            return ERROR;
//    }
//    return OK;
//}
//
//int Height_BiTree(BiTree T)
//{
//	int h1, h2;
//	if(!T)	return 0;//T为空树
//	h1 = Height_BiTree(T->lchild);
//	h2 = Height_BiTree(T->rchild); 
//	return (fmax(h1 , h2) + 1);
//} 
//
//int LeafCount_BiTree(BiTree T)
//{
//	int num1, num2;
//	if(!T)	return 0;//若T为空树
//	if(T->lchild == NULL && T->rchild == NULL)	return 1;//T为叶子结点 
//	num1 = LeafCount_BiTree(T->lchild);//求左子树的叶子数 
//	num2 = LeafCount_BiTree(T->rchild);//求右子树的叶子数 
//	return (num1 + num2);
//}
//
//void Level_BiTree(BiTree T, int i)
//{
//	if(!T)	return ;//若T为空树 
//	T->data = i;
//	Level_BiTree(T->lchild, i + 1);//求左子树的节点层数 
//	Level_BiTree(T->rchild, i + 1);//求右子树的节点层数 
//} 
//
//int Decendents(BiTree T,char e)
//{
//	int found;
//	if(!T)	return ;//遇空树，直接返回 
//	if(T->data == e)	found = 1;//先序遍历时找到e,置“找到”标记 
//	if(found)	Visit(T->data);//访问该结点，如打印 
//	Decendents(T->lchild, e);//递归地在左子树中搜索 
//	Decendents(T->rchild, e);//递归地在右子树中搜索 
//	if(T->data == e)	found = 0;//后序遍历时找到e,置“退出”以e为根的子树标记 
// } 
// 
// 
//int Height_BiNode(BiTree T)
//{
//	int h1, h2;
//	if(!T)	return 0;//空树的高度为0 
//	h1 = Height_BiNode(T->lchild);//求左孩子的高度 
//	h2 = Height_BiNode(T->rchild);//求右孩子的高度 
//	T->data = fmax(h1, h2) + 1;//求出节点高度 
//	return T->data;//返回所求高度，以便求父节点的高度 
//} 
//
//// Function to free the memory allocated for the binary tree
//void DestroyBiTree(BiTree *T) 
//{
//    if (*T) 
//	{
//        DestroyBiTree(&((*T)->lchild)); // Recursively free left subtree
//        DestroyBiTree(&((*T)->rchild)); // Recursively free right subtree
//        free(*T); // Free current node
//        *T = NULL;
//    }
//}
//
//// Function to perform inorder traversal (left-root-right) and print the binary tree
//void InOrderTraversal(BiTree T) 
//{
//    if (T) 
//	{
//        InOrderTraversal(T->lchild); // Traverse left subtree
//        printf("%c ", T->data);      // Print root
//        InOrderTraversal(T->rchild); // Traverse right subtree
//    }
//}
//
//// Function to perform preorder traversal (root-left-right) and print the binary tree
//void PreOrderTraversal(BiTree T) {
//    if (T) {
//        printf("%c ", T->data);      // Print root
//        PreOrderTraversal(T->lchild); // Traverse left subtree
//        PreOrderTraversal(T->rchild); // Traverse right subtree
//    }
//}
//
//// Function to perform postorder traversal (left-right-root) and print the binary tree
//void PostOrderTraversal(BiTree T) {
//    if (T) {
//        PostOrderTraversal(T->lchild); // Traverse left subtree
//        PostOrderTraversal(T->rchild); // Traverse right subtree
//        printf("%c ", T->data);        // Print root
//    }
//}
//
//int main() {
//    BiTree T = NULL;
//    printf("Enter the binary tree (use '#' for empty nodes):\n");
//    if (CreateBiTree(&T) == OK) {
//        printf("Binary tree created successfully!\n");
//        
//        printf("Inorder traversal: ");
//        InOrderTraversal(T);
//        printf("\n");
//        
//        printf("Preorder traversal: ");
//        PreOrderTraversal(T);
//        printf("\n");
//        
//        printf("Postorder traversal: ");
//        PostOrderTraversal(T);
//        printf("\n");
//    } else {
//        printf("Failed to create binary tree.\n");
//    }
//
//    // Free the memory allocated for the binary tree
//    DestroyBiTree(&T);
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 1
#define ERROR 0

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

int CreateBiTree(BiTree *T) {
    char ch;
    scanf("%c", &ch);
    getchar(); // Consume the newline character

    if (ch == '#')
        *T = NULL;
    else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T)
            exit(EXIT_FAILURE);

        (*T)->data = ch;

        if (CreateBiTree(&((*T)->lchild)) == ERROR)
            return ERROR;
        if (CreateBiTree(&((*T)->rchild)) == ERROR)
            return ERROR;
    }
    return OK;
}

int Height_BiTree(BiTree T) {
    if (!T)
        return 0;
    int left_height = Height_BiTree(T->lchild);
    int right_height = Height_BiTree(T->rchild);
    return fmax(left_height, right_height) + 1;
}

int LeafCount_BiTree(BiTree T) {
    if (!T)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return 1;
    return LeafCount_BiTree(T->lchild) + LeafCount_BiTree(T->rchild);
}

void Level_BiTree(BiTree T, int level) {
    if (T) {
        printf("%c at level %d\n", T->data, level);
        Level_BiTree(T->lchild, level + 1);
        Level_BiTree(T->rchild, level + 1);
    }
}

void Visit(char data) {
    printf("%c ", data);
}

int found = 0;

void Decendents(BiTree T,char e)
{
	if(!T)	return ;//遇空树，直接返回 
	if(T->data == e)	found = 1;//先序遍历时找到e,置“找到”标记 
	if(found)	Visit(T->data);//访问该结点，如打印 
	Decendents(T->lchild, e);//递归地在左子树中搜索 
	Decendents(T->rchild, e);//递归地在右子树中搜索 
	if(T->data == e)	found = 0;//后序遍历时找到e,置“退出”以e为根的子树标记 
 }

void InOrderTraversal(BiTree T) {
    if (T) {
        InOrderTraversal(T->lchild);
        printf("%c ", T->data);
        InOrderTraversal(T->rchild);
    }
}

void PreOrderTraversal(BiTree T) {
    if (T) {
        printf("%c ", T->data);
        PreOrderTraversal(T->lchild);
        PreOrderTraversal(T->rchild);
    }
}

void PostOrderTraversal(BiTree T) {
    if (T) {
        PostOrderTraversal(T->lchild);
        PostOrderTraversal(T->rchild);
        printf("%c ", T->data);
    }
}

void DestroyBiTree(BiTree *T) {
    if (*T) {
        DestroyBiTree(&((*T)->lchild));
        DestroyBiTree(&((*T)->rchild));
        free(*T);
        *T = NULL;
    }
}

int main() {
    BiTree T = NULL;
    printf("Enter the binary tree (use '#' for empty nodes):\n");
    if (CreateBiTree(&T) == OK) {
        printf("Binary tree created successfully!\n");

        printf("Inorder traversal: ");
        InOrderTraversal(T);
        printf("\n");

        printf("Preorder traversal: ");
        PreOrderTraversal(T);
        printf("\n");

        printf("Postorder traversal: ");
        PostOrderTraversal(T);
        printf("\n");

        printf("Height of the binary tree: %d\n", Height_BiTree(T));
        printf("Number of leaf nodes: %d\n", LeafCount_BiTree(T));

        printf("Nodes at different levels:\n");
        Level_BiTree(T, 1);

        char node_to_find;
        printf("Enter a node to find its descendants: ");
        scanf(" %c", &node_to_find);
        //printf("Descendants of node %c: ", node_to_find);
        Decendents(T, node_to_find);
        printf("\n");
    } else {
        printf("Failed to create binary tree.\n");
    }

    DestroyBiTree(&T);
    return 0;
}


