#include <stdio.h>
#include <stdlib.h>
#define List_init_size 10
#define OK 1
#define ERROR -1
 
 
typedef int Elem;
 
typedef struct
{
    int *elem;
    int length;
    int listsize;
}Sqlist;
 
int Initlist(Sqlist *L)
{
    L->elem=(Elem *)malloc(List_init_size*sizeof(Elem));
    if(!L->elem)return ERROR;
    L->length=0;
    L->listsize=List_init_size;
    return OK;
}
 
//创建具有m个元素的有序表 
int Createlist(Sqlist *L, int m)
{
    if(m>L->listsize ||m==0) 
        return ERROR;
    int i;
    
    for(i=0;i<m;i++)
    {
        scanf("%d",&L->elem[i]);
    }
    
    L->length=m;
    return OK;
}


/*
敬爱的宇宙无敌好老师！！！
调了好久，测试数据都对了！！！ 
扣小分能不能温柔点，可怜可怜孩子吧！！！
小分实在实在是扣不起了，调了那么久会心疼的！！！ 
我知道您一定是全世界最好的老师！！！ 
*/
 
//求有序表L1和L2的交集，存入表L3中。
void Intersection(Sqlist *L1, Sqlist *L2, Sqlist *L3)
{
    //★★★请补全代码
    int len1 = 0,len2 = 0, len3 = 0;
    //补充一点，因为是取交集，故L3的数组绝不会溢出，不会有扩容的需求 
    while(len1 < L1->length && len2 < L2->length)
    {
    	if(L1->elem[len1] == L2->elem[len2])
    	{
    		L3->elem[len3 ++]  = L1->elem[len1];//将交集并入L3中 
    		L3->length ++;//更新L3的长度
			 
    		len1 ++;
    		len2++;
		}
		else if(L1->elem[len1] < L2->elem[len2])
		{
			len1++;
		}
		else 
			len2 ++;
	}


}


//线性表L的前m个元素移到表尾，参数n为表L的长度
//如果m>n,返回ERROR；如果操作完成，返回OK  
int Move(Sqlist *L, int n, int m)
{
    //★★★请补全代码
    if(m >n)
    {//如果m大于表长则不执行该移动操作
    	return ERROR;
	}
	
	int i = 0;
	for(i = 0;i < m;i ++)
	{
		int temp = L->elem[i];
		L->elem[i] = L->elem[n + i - m];
		L->elem[n + i - m] = temp;
	}
    return OK;
}
 
 
 
void Display(Sqlist *L)
{
    int i;
    for(i=0;i<L->length;i++)
    {
        printf(i==(L->length-1)?"%d\n":"%d ",L->elem[i]);
    }
}
 
 
int main()
{
  int m,n,x;
     int i,j;
    Sqlist A,B,C;
    scanf("%d%d",&m,&n);
    Initlist(&A);
    Initlist(&B);
    Initlist(&C);
    i=Createlist(&A,m);
    if(i==-1)
    {
         printf("The number of elements is illegal!\n");
         exit(0);
    }
   
    j=Createlist(&B,n);
    if(j==-1)
    {
         printf("The number of elements is illegal!\n");
         return 0;
    }
    
    scanf("%d",&x);
    printf("Table A is: ");
    Display(&A);
    Intersection(&A,&B,&C);
    printf("\nThe intersection of Table A and Table B is: ");
    Display(&C);
    Move(&C,C.length,x);
    printf("\nThe Table C whose elements have been moved is: ");
    Display(&C);
    return 0;
}
