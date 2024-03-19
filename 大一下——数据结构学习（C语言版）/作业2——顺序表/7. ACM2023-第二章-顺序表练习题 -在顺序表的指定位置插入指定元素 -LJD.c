#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
#define INIT_SIZE 100
#define LISTINCREMENT 10  
typedef int ElemType;

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
} SqList;

// 创建一个空的顺序表
Status InitList_Sq(SqList *L) {
    L->elem = (int *)malloc(INIT_SIZE * sizeof(int));
    if (!L->elem) return OVERFLOW;
    L->length = 0;
    L->listsize = INIT_SIZE;
    return OK;
}

// 创建一个带有 n 个元素的数组列表
Status CreateList_Sq(SqList *L, int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        L->elem[i] = a[i];
    }
    L->length = n;
    return OK;
}

// 在顺序表 L 的特定位置插入元素
Status InsertList_Sq(SqList *L, int i, ElemType e) {    
    if (i < 1 || i > L->length + 1) return ERROR;
    if (L->length >= L->listsize) return OVERFLOW; // 检查是否需要扩展顺序表的空间
    int j;
    for (j = L->length - 1; j >= i - 1; j--) {
        L->elem[j + 1] = L->elem[j]; // 将元素后移
    }
    L->elem[i - 1] = e;
    L->length++;
    return OK;
}

// 打印所有元素
void PrintList_Sq(SqList L) {
    int i;
    for (i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]); 
    }
}

int main() {
    int n, e, k;
    scanf("%d", &n);
    int i, arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    SqList sq;
    InitList_Sq(&sq);
    CreateList_Sq(&sq, arr, n);
    scanf("%d%d", &e, &k);
    InsertList_Sq(&sq, k, e);
    PrintList_Sq(sq);
    return 0;
}

