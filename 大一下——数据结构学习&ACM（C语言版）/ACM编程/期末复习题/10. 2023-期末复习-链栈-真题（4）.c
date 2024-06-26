#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
typedef int SElemType;


//定义链栈结构
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode,*LinkStack;

//初始化链栈
Status InitStack(LinkStack *S)
{
	LinkStack Head=(LinkStack)malloc(sizeof(StackNode));
	if(!Head)	return ERROR; 
	Head->next=NULL;
	(*S)=Head;
	return OK;
}

//判断链栈是否为空，是则返回TRUE，不是则返回FALSE
Status StackEmpty(LinkStack S)
{
	if (NULL==S->next)
		return TRUE;
	else
		return FALSE;
}

//将元素e入栈
Status Push(LinkStack *S, SElemType e)
{   
	StackNode *top=(*S)->next;
	StackNode *temp;
	temp = (LinkStack)malloc(sizeof(StackNode));
	temp->data = e;
	temp->next=(*S)->next;
	(*S)->next=temp;
	return OK;
}

//弹出栈顶元素，赋值给e
Status GetTop(LinkStack S, SElemType *e)
{
	if (StackEmpty(S)==TRUE)
		return ERROR;
	*e = S->next->data;
	return OK;
}

//出栈，出栈元素赋值给e
Status Pop(LinkStack *S, SElemType *e)
{
	StackNode *top=(*S)->next;
	if (StackEmpty(*S)==TRUE)
		return ERROR;
	*e = top->data;
	(*S)->next = top->next;
	free(top);
	return OK;
}

int main()
{
	LinkStack S;
//	int n=0;  //通过整数n统计相同数的个数，若相同，则每次进栈后n+1
	InitStack(&S);  //初始化栈
	
	//★★★请补全代码
	
//	int arr[MAXSIZE] ,i = 0, temp;
//	while(1)
//	{
//		scanf("%d", &temp);
//		if(temp == -1)	break;
//		arr[i ++] = temp;
//	}
	
	
	
	while(1)
	{
		int a = 0;
		scanf("%d", &a);
		if(a == -1)	break;
		Push(&S, a);
	 }
	 int e = -1, e_pre = -1;
	 while(!StackEmpty(S)) 
	 {
	 	Pop(&S, &e);
	 	GetTop(S, &e_pre);
	 	if(e != e_pre || StackEmpty(S))	
	 	{
	 		printf("%d ", e);
		}
		else
		{
			while(!StackEmpty(S) && e == e_pre)
			{
				Pop(&S, &e);
				if(!StackEmpty(S))	GetTop(S, &e);
			}
//			if(e != e_pre) Push(&S, e);
		}
	 }
	
	return 0;

}
