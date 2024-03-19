#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
typedef char SElemType;

// 定义链表栈节点结构
typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

// 函数声明
Status InitStack(LinkStack *S);
Status StackEmpty(LinkStack S);
Status Push(LinkStack *S, char ch);
Status Pop(LinkStack *S, char *ch);
Status GetTop(LinkStack S, char *e);
Status match(char element_l, char element_r);

// 初始化链表栈
Status InitStack(LinkStack *S) {
    (*S) = (LinkStack)malloc(sizeof(StackNode));
    if (!(*S))
        return ERROR;
    (*S)->next = NULL;
    return OK;
}

// 判断栈是否为空
Status StackEmpty(LinkStack S) {
    return S->next == NULL ? TRUE : FALSE;
}

// 元素入栈
Status Push(LinkStack *S, char ch) {
    LinkStack s = (LinkStack)malloc(sizeof(StackNode));
    if (!s)
        return ERROR;
    s->data = ch;
    s->next = (*S)->next;
    (*S)->next = s;
    return OK;
}

// 元素出栈
Status Pop(LinkStack *S, char *ch) {
    if (StackEmpty(*S))
        return ERROR;
    LinkStack p = (*S)->next;
    *ch = p->data;
    (*S)->next = p->next;
    free(p);
    return OK;
}

// 获取栈顶元素
Status GetTop(LinkStack S, char *e) {
    if (StackEmpty(S))
        return ERROR;
    *e = S->next->data;
    return OK;
}

// 检查两个括号是否匹配
Status match(char element_l, char element_r) {
    if (element_l == '(') {
        return (element_r == ')') ? TRUE : FALSE;
    } else if (element_l == '[') {
        return (element_r == ']') ? TRUE : FALSE;
    } else if (element_l == '{') {
        return (element_r == '}') ? TRUE : FALSE;
    } else {
        exit(0);
    }
}

int main() {
	//SetConsoleOutputCP(65001);
    LinkStack S;
    char e;
    int length = 0,i;
    char str[MAXSIZE];

    InitStack(&S);
    scanf("%s", str); // 输入一串括号
    length = strlen(str);

    for (i = 0; i < length; i++) {
        switch (str[i]) {
            case '(':
            case '[':
            case '{':
                Push(&S, str[i]);
                break;
            case ')':
            case ']':
            case '}':
                if (StackEmpty(S)) {
                    printf("右括号多余\n");
                    exit(0);
                } else {
                    GetTop(S, &e);
                    if (match(e, str[i])) {
                        Pop(&S, &e);
                    } else {
                        printf("左右括号不匹配\n");
                        exit(0);
                    }
                }
                break;
            default:
                exit(0);
        }
    }

    if (StackEmpty(S)) {
        printf("括号匹配\n");
    } else {
        printf("左括号多余\n");
    }

    return 0;
}

