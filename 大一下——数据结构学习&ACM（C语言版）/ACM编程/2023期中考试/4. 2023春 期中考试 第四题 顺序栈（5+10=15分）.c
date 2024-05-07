#include<stdio.h>

#include<stdlib.h>

#define OK 1

#define ERROR 0

#define OVERFLOW -2

#define MAXSIZE  100



typedef int Status;

typedef int SElemType;

typedef struct{

	SElemType *base;

	SElemType *top;

	int stacksize;

}SqStack;



//顺序栈的初始化

Status InitStack(SqStack *S){ 

	S->base = (SElemType *)malloc(MAXSIZE * sizeof(SElemType));

	if(!S->base)

		return ERROR;

	S->top = S->base;

	S->stacksize = MAXSIZE;

	return OK;

}



Status Push(SqStack *S,SElemType e)
{

	//★★★请补全代码
	if(S->top - S->base >= S->stacksize)	return ERROR;
	*(S->top ++) = e;
	return OK;


}



//顺序栈的出栈

Status Pop(SqStack *S,SElemType *e){

	if(S->base == S->top)

		return ERROR;

	*e = *(--S->top);

	return OK;

}





// 将一个十进制数转换为二进制数，并打印输出

// 要求使用堆栈来实现，如果未用堆栈，答题无效



int main()

{

	//★★★请补全代码
	int n;
	scanf("%d",&n);
	if(n <= 0)
	{
		printf("Input error!");
		return 0;
	}
	
	SqStack S;
	InitStack(&S);
	
	while(n)
	{
		int x = n%2;
		Push(&S,x);
		n = (n - x) / 2;
	}
	
	while(S.base != S.top)
	{
		int e;
		Pop(&S,&e);
		printf("%d",e);
	}
	return 0;
}






