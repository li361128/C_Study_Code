#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

static int step = 0;

//移动函数

void move(int n, char *A, char *B)

{

    printf("将%d从%c移动到%c.\n", n, *A, *B);

    step++;

    return;

 

}

 

//将n层汉诺塔从A移动到C，B作为辅助

void Hanoi(int n, char *A, char *B, char *C)

{

/* 代码填在这里 */
	if(n == 1)	move(n,A,C);
	else
	{
		Hanoi(n - 1,A,C,B);
		move(n,A,C);
		Hanoi(n - 1,B,A,C);	
	} 

 

}

 

int main()

{

    int n;

    char axle[3]={'A','B','C'};

 

    printf("输入层数n:");

    scanf("%d",&n);

 

    Hanoi(n, axle, axle+1, axle+2);

    printf("移完%d层汉诺塔所用总步数为%d\n", n, step);

    return 0;

}


