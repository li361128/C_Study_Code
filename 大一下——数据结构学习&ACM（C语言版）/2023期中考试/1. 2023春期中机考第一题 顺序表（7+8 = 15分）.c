#include <stdio.h>

#include <stdlib.h>

#define OK 1

#define ERROR 0



typedef struct

{

	int *elem;

	int length;

	int listsize;

} sqlist;



//初始化一个空的顺序表

int initlist(sqlist *l)

{

	l->elem = (int *)malloc(100 * sizeof(int));

	if (!l->elem)

		return ERROR;

	l->length = 0;

	l->listsize = 100;

	return OK;

}



//根据长度为n的数组x，创建顺序表L   

//如果成功返回OK，否则返回ERROR

int insertlist(sqlist *l, int a[], int n)

{
	int i; 
	for (i = 0; i < n; i++)

	{

		l->elem[i] = a[i];

	}

	l->length = n;

	return OK;

}



//将顺序表a中大于t的元素存入顺序表b中

void getb(sqlist *b, sqlist a, int t)

{

	//★★★请补全代码
	int i = 0,j = 0;
	for(;i < a.length;i ++)
	{
		if(a.elem[i] > t)	
		{
			b->elem[j + b->length] = a.elem[i];	
			j ++;
		}
	} 
	b->length += j;







}



// 将b中的元素逆置，并打印输出逆置后b中所有元素

void  reverselist(sqlist *b)

{

	//★★★请补全代码
	int i = 0;
	for(;i * 2 < b->length;i ++)
	{
		int temp = b->elem[i];
		b->elem[i] = b->elem[b->length - i - 1];
		b->elem[b->length - i - 1] = temp;
		
	}

}



int main()

{

	sqlist a,b;

	initlist(&a);

	initlist(&b);

	int x[100];

	int n,i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)

	{

		scanf("%d", &x[i]);

	}

	insertlist(&a, x, n);

	int t;

	scanf("%d", &t);

	getb(&b, a, t);

	reverselist(&b);
	
	for(i = 0;i < b.length;i ++)
	{
		printf("%d ",b.elem[i]);
	}

	return 0;

}


