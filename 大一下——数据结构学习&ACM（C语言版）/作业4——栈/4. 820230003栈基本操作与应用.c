#define BASE 17

#include <stdio.h>
#include <stdlib.h>

#define Status int
#define SElemType char

#define STACK_INIT_SIZE 100        //存储空间的初始分配量
#define STACKINCREMENT  10          //存储空间的分配增量
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

//栈数据结构
typedef struct Stack 
{
    SElemType *base;    //栈底指针
    SElemType *top;     //栈顶指针
    int stacksize;      //栈可用的最大容量
} SqStack;

//初始化函数
Status InitStack(SqStack *S) 
{
    S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base) 
    {
        printf("init fail\n");
        return ERROR;
    }
    S->top = S->base;     //栈顶指针与栈底相同
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

//销毁 
Status DestroyStack(SqStack *S) 
{
    //补全代码
	free(S->base);
	S->base = NULL;
	S->top = NULL;  
	S->stacksize = 0;
	if(S->base)	
	{
		printf("Fail Destroy");
		return ERROR;
	}
	return OK;
}

//清空 
Status ClearStack(SqStack *S) 
{
    S->top = S->base;
    return OK;
}

//判断是否为空 
Status StackEmpty(SqStack S) 
{
    if (S.top == S.base) 
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack S) 
{
    return S.top - S.base;
}

//得到栈顶元素，不修改指针
Status GetTop(SqStack S, SElemType *e) 
{ 
    if (S.top == S.base) 
        return ERROR;
    *e = *(S.top - 1);
    return OK;
}

//入栈
Status Push(SqStack *S, SElemType e) 
{
    if (S->top - S->base >= S->stacksize) 
    {  //栈满,追加存储空间
        S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S->base) 
            return ERROR;
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top++ = e;
    return OK;
}

//出栈
Status Pop(SqStack *S, SElemType *e) 
{
    if (S->top == S->base) 
        return ERROR;    //栈空
    *e = *--S->top;
    return OK;
}

//遍历栈
Status StackTraverse(SqStack S) 
{
    if (S.base == NULL)
        return ERROR;
    if (S.top == S.base)
        printf("empty\n");
    SElemType *p;
    p = S.top;
    while (p > S.base) 
    {
        p--;
        printf("%c", *p);//从栈顶开始打印，而且未修改栈顶指针 
    }
    return OK;
}

void conversion(SqStack *S) 
{
    //补全代码
    int decimal = 0;
    scanf("%d",&decimal);
    char base17[20] = "0123456789ABCDEFG";
    while(decimal)
    {
    	int index = decimal % 17;
    	Push(S,base17[index]);
    	decimal /=17;
	}
	StackTraverse(*S);
}

//主函数
int main() 
{
    SqStack S;
    InitStack(&S);
    conversion(&S);
    DestroyStack(&S);
    return 0;
}

