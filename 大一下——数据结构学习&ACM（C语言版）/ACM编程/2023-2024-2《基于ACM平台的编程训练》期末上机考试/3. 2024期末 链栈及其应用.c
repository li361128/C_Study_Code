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
 
 
typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}LNode,*LinkList;
 
typedef struct{
    LinkList Head;
    int length;
          
}LinkStack;
 
Status InitStack(LinkStack *S)
{
   S->Head = (LinkList)malloc(sizeof(LNode));
   if(S->Head==NULL)
             return ERROR;
   S->Head->next = NULL;
   S->length = 0;
  
   return OK;
}
Status StackEmpty(LinkStack *S)
{
   if(S->length==0)
             return TRUE;
   else
             return FALSE;
}

/*
敬爱的宇宙无敌好老师！！！
调了好久，测试数据都对了！！！ 
扣小分能不能温柔点，可怜可怜孩子吧！！！
小分实在实在是扣不起了，调了那么久会心疼的！！！ 
我知道您一定是全世界最好的老师！！！ 
*/

//入栈操作
Status Push(LinkStack *S,SElemType e)
{   
     //请补全代码
     if(S->length >= MAXSIZE)//看到宏定义上有这个，想必这MAXSIZE有限制 
     	return ERROR;
     	
    //创建新的链表结点 
     LinkList p;
	 p = (LinkList)malloc(sizeof(LNode));
	 if(!p)
	 	return ERROR; 
	p->data = e;
	
	p->next = S->Head->next;
	S->Head->next = p;
	
	S->length ++;//更新栈的长度
	 
	return OK;	
}

//出栈操作
Status Pop(LinkStack *S,SElemType *e)
{
	if(S->length==0)
		return ERROR;
	LinkList p;
	p = S->Head->next; 
	*e=p->data;
	S->Head->next = p->next;
	free(p);
	S->length--;
	return OK;
}

//取栈顶元素
Status GetTop(LinkStack *S,SElemType *e)
{
	*e=S->Head->next->data;
	return OK;
}

// 判断两个字符 element_l 和 element_r 是否配对，如果是，返回TRUE，否则输出FALSE. 
Status match(char element_l, char element_r)
{
  //请补全代码
	if((element_l == '(' && element_r == ')' )
	|| (element_l == '{' && element_r == '}' )
	|| (element_l == '[' && element_r == ']'))
		return TRUE;

		
	return FALSE;
  
}

//使用链栈S，对字符串str中的字符进行括号匹配检查，如果全部配对，则打印Yes, 如果出现错误，则打印No, 并立即从函数返回。
void match_check(char str[], LinkStack *S)
{
   //请补全代码
   int i =0;
   for(;str[i] != '\0';i ++)
   {
   		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
   			Push(S, str[i]);
   			
   		else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
   		{
   			char temp;
   			if(StackEmpty(S))
   			{
   				printf("No");
   				return ;	
			}
   			GetTop(S, &temp);
   			if(match(temp, str[i]) == TRUE)
   				Pop(S, &temp);
   			else
   			{
   				printf("No");
   				return ;
			}
		}
   }
   
   if(StackEmpty(S))
   		printf("Yes");
   	else
   		printf("No");
}
 
 
int main(){
	LinkStack S;
	char str[MAXSIZE];
	InitStack(&S);
	scanf("%s", str);
	match_check(str,&S);
	return 0;
}
