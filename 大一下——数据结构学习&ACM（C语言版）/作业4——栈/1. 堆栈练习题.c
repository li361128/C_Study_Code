#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Stack
{
	int top;
	unsigned capacity;
	char * array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (char*)malloc(stack->capacity*sizeof(char));
	return stack;
}

int isFull(struct Stack stack)
{
	int full = 0;
	full = (stack.top == (int)stack.capacity - 1)?1:0;
	return full;
}

int isEmpty(struct Stack stack)
{
	return stack.top == -1;
}

void push(struct Stack *stack,char item)
{
	if(stack->top == stack->capacity)	return;	
	stack->array[++stack->top] = item;	
}

char pop(struct Stack *stack)
{
	if(!isEmpty(*stack))	return stack->array[stack->top--];
}

void reverseStr(char *str)
{
	int i = 0;
	struct Stack* stack  = createStack(strlen(str) + 1);
	for(;str[i] != '\0';i ++)
	{
		push(stack,str[i]);
	}
	for(i = 0;str[i] != '\0';i ++)
	{
		str[i] = pop(stack);
	}
    printf("%s\n", str);
}

int main()
{
	char str[] = "ILoveChina, ILoveBJTU, ILoveGJCXSJXL";

    //printf("The given string %s has %d characters.\n", str, strlen(str));

    reverseStr(str);
//
//	int i = 0;
//	struct Stack* stack  = createStack(strlen(str) + 1);
//	for(;str[i] != '\0';i ++)
//	{
//		push(stack,str[i]);
//	}
//	for(i = 0;str[i] != '\0';i ++)
//	{
//		str[i] = pop(stack);
//	}
//    printf("%s\n", str);
	return 0;
}
