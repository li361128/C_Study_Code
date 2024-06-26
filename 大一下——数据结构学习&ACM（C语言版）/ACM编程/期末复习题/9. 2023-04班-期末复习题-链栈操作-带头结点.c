// LZHead.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
	int data;
	struct Stack* next;
}ListStack;

//init_Stack
ListStack* init_Stack(ListStack *head)
{
	ListStack*p = (ListStack*)malloc(sizeof(ListStack));
	p->data = -1;
	p->next = NULL;
	return p;
}

//push_Stack
ListStack* push_Stack(ListStack *head, int x)
{
	
 	ListStack *r = init_Stack(head);
	r->data = x;
	r->next = head->next;
	head->next = r;
	return head;		
}

//pop_Stack
int pop_Stack(ListStack *head, int *d)
{
	if(!head->next)	return 0;
	
	ListStack *r = (*head).next ;	
	*d = r->data;
	head->next = r->next;
	free(r);
	return 1;
}

int stack_Top(ListStack *head, int *num)
{
	if(!head->next)	return 0;
	*num = head->next->data;
	return 1;
}

int count_stack(ListStack *head)
{
    int total = 0;
    ListStack *p = head->next;
    while (p != NULL)
    {
        total++;
        p = p->next;
    }
    return total;
}
//text 
int main()
{
	struct Stack *head;
	int n, num = -1, length, i;
	head = NULL;
	head = init_Stack(head);//初始化 
	/*入栈*/
	head = push_Stack(head, 35);
	head = push_Stack(head, 45);
	head = push_Stack(head, 55);
	head = push_Stack(head, 65);
	head = push_Stack(head, 75);
	head = push_Stack(head, 85);
	stack_Top(head, &n);
	    printf("栈顶元素为：%d\n",n);
	length = count_stack(head);
	for (i = 0; i < length; i++)
	{
		pop_Stack(head, &num);
		printf("出栈元素为：%d\n",num);
	}
	return 0;
}


