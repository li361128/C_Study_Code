#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

// Definition of node structure of singly linked list
typedef struct L_node
{
    ElemType data;           // data field 
    struct L_node *next;     // pointer field
} LNode, *LinkedList;

// Initialize a singly linked list L with head node
Status InitLinkList(LinkedList *L)
{
    (*L) = (LNode *) malloc(sizeof(LNode));
    if (!(*L))
        return ERROR;
    (*L)->next = NULL;
    return OK;
}

// Create a singly linked list L with head node, and with n elements
Status CreateList_L(LinkedList L, int a[], int n)
{
    LNode *p = L;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        LNode *r = (LNode *) malloc(sizeof(LNode));
        if (!r)
            return ERROR;
        r->data = a[i];
        r->next = NULL;
        p->next = r;
        p = r;
    }
    return OK;
}

// Merge two singly linked lists La and Lb into Lc
void Merge_L(LinkedList *La, LinkedList *Lb, LinkedList *Lc)
{
    LNode *a = (*La)->next;
    LNode *b = (*Lb)->next;
    LNode *c = (*Lc);
    LNode *c1;

    while (a && b)
    {
        c1 = (LNode *) malloc(sizeof(LNode));
        if (!c1)    return; // Allocation failed

        if (a->data <= b->data)
        {
            c1->data = a->data;
            a = a->next;
        } else
        {
            c1->data = b->data;
            b = b->next;
        }
        c1->next = NULL;
        c->next = c1;
        c = c1;
    }

    while (a)
    {
        c1 = (LNode *) malloc(sizeof(LNode));
        if (!c1)    return; // Allocation failed
        c1->data = a->data;
        c1->next = NULL;
        c->next = c1;
        c = c1;
        a = a->next;
    }

    while (b)
    {
        c1 = (LNode *) malloc(sizeof(LNode));
        if (!c1)   return;
		c1->data = b->data;
        c1->next = NULL;
        c->next = c1;
        c = c1;
        b = b->next;
    }
}

// Print the elements in a list
void LinkedListPrint(LinkedList L)
{
    LNode *p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    LNode *La, *Lb, *Lc;
    InitLinkList(&La);
    InitLinkList(&Lb);
    InitLinkList(&Lc);

    int n, m;
    scanf("%d", &n);
    int a[n];
    int i = 0;
    for (i = 0; i < n; i++)     scanf("%d", &a[i]);

    CreateList_L(La, a, n);

    scanf("%d", &m);
    int b[m];
    for (i = 0; i < m; i++)     scanf("%d", &b[i]);

    CreateList_L(Lb, b, m);

    Merge_L(&La, &Lb, &Lc);

    LinkedListPrint(Lc);

    return OK;
}  

