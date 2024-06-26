#include "stdio.h"

#include "stdlib.h"

#define OK 1

#define ERROR 0

#define TRUE 1

#define FALSE 0

#define MAXSIZE  20   //堆栈的最大容量

typedef int Status;

typedef char ElemType;

 

//顺序栈的结构定义

typedef struct

{

         ElemType data[MAXSIZE]; //存放堆栈元素的数组

         int top;                 //top指向栈顶元素，top=-1，表示空栈

} SqStack;

 

//初始化一个空栈

void InitStack(SqStack *S)

{

         S->top = -1;

}

Status Push(SqStack *S, ElemType e)

{

//★★★请补全代码
	if((S->top + 1) > MAXSIZE) return ERROR;
	S->top ++;
	S->data[S->top] = e;


 

 

return OK;

}

 

Status Pop(SqStack *S, ElemType *e)

{

//★★★请补全代码
		if(S->top == -1)	return ERROR;
		*e = S->data[S->top];
		S->top--;
         return OK;

}

 

//如果是空栈，返回1，否则返回0

Status StackEmpty(SqStack S)

{

         return S.top == -1;

}

 

char GetTop(SqStack S, ElemType *e)

{

//★★★请补全代码
	if(S.top == -1)	return ERROR;
	*e = S.data[S.top];
	return *e;
 

    
}

 

int main()

{

         char a[21], b[21];// 增加1以适应gets函数的'\0'结尾

         char temp;

         SqStack Stack;

         InitStack(&Stack);

         printf("Please enter a string with a length no longer than 20:\n");

         gets(a);

        int i = 0;
        char e;
        for(;a[i] != '\0';i ++)
        {
        	if(StackEmpty(Stack) || GetTop(Stack,&e) != a[i])
        	{

        		Push(&Stack,a[i]);
			}
			else 
			{
		   		if(a[i] == a[i + 1])	continue;
				Pop(&Stack,&e);
			}
		}
		int j = 0;
		while(StackEmpty(Stack) == 0)
		{
			Pop(&Stack,&b[j++]);
		}
		printf("The resulting string is: ");
		for(j = j - 1;j >= 0;j --)
		{
			printf("%c",b[j]);
		}

//★★★请补全代码

 

         return 0;

}
