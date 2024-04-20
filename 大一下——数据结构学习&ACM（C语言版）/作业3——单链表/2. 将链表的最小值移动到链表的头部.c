#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int Status;

// Definition of a node structure for a singly linked list
typedef struct L_node 
{
    ElemType data;           // Data field
    struct L_node *next;     // Pointer field
} LNode, *LinkedList;

//===========================================
// Initialize a singly linked list L with a head node
//===========================================
Status InitList_L(LinkedList *L)
{
    *L = (LNode*)malloc(sizeof(LNode));
    if (!(*L))     return ERROR;
    (*L)->next = NULL;
    return OK;
}

//===========================================
// Create a singly linked list L with a head node, and with n elements
//===========================================
Status CreateList_L(LinkedList *L, ElemType a[], int n)
{
    if (n <= 0)    return ERROR;
    LNode *r = *L;  // r points to the head node
    int j = 0;
    for (; j < n; j++)
    {
        LNode *p = (LNode*)malloc(sizeof(LNode));  // Create a new node
        if (!p)   return ERROR; 
        p->data = a[j];  // Assign data to the new node
        p->next = NULL;  // Set next pointer to NULL

        r->next = p;     // Link the new node to the list
        r = p;           // Move r to the newly added node
    }
    return OK;
}

//===========================================
// Find the minimum value in an array
//===========================================
int find_Min(int arr[], int n)
{
    int min = arr[0], i = 1;
    for (; i < n; i++)
    {
        if (arr[i] < min)     min = arr[i];
    }
    return min;
}

//===========================================
// Move the node containing the minimum value to the head of the linked list
//===========================================
void MoveMinNode_L(LinkedList L, ElemType minval)
{
    // 如果链表为空或者输入无效，无需操作
    if (!L || !L->next)   return;
        
    // 用于跟踪最小值节点前面的节点
    LNode *prev = NULL;

    // 遍历链表的指针
    LNode *cur = L->next;

    // 寻找包含最小值的节点
    while (cur && cur->data != minval)
    {
        prev = cur;
        cur = cur->next;
    }

    // 如果找不到最小值或者最小值已经在链表头部，无需移动
    if (!cur || cur == L->next)    return;

    // 将包含最小值的节点从当前位置分离出来
    prev->next = cur->next;

    // 将分离的节点插入到链表头部
    cur->next = L->next;
    L->next = cur;
}

//void MoveMinNode_L(LinkedList L, ElemType minval)
//
//{
//	if(!L->next) return;
//	LNode* r = L;
//	while(r && r->next->data != minval)	r = r->next;//找到minval的前一个结点 
	//类似于进行一个删除操作 
//	LNode* p = r->next;
//	r->next = p->next;
// 	free(p);
	//类似进行一个插入操作 
// 	LNode *s = L;
//	LNode*q;
//	q = (LNode*)malloc(sizeof(LNode));
//	q->data = minval;
//	q->next = s->next;
//	s->next = q;
//}


//===========================================
// Print the elements in a linked list
//===========================================
void LinkedListPrint(LinkedList L)
{
    LNode *p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    int i; 
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min = find_Min(arr, n);
    //printf("Minimum value: %d\n", min);
    printf("%d\n",min);

    LinkedList L;
    if (InitList_L(&L) == ERROR)
    {
        printf("Error: Failed to initialize the list.\n");
        return 1;
    }

    if (CreateList_L(&L, arr, n) == ERROR)
    {
        printf("Error: Failed to create the list.\n");
        return 1;
    }

    MoveMinNode_L(L, min);
    //printf("List after moving the minimum value to the head: ");
    LinkedListPrint(L);

    return 0;
}

