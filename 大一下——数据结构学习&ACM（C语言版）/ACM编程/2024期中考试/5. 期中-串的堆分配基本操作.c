//串赋值函数未正确分配正确空间， 扣2分
//插入函数释放后未分配空间， 扣2分
#include <stdio.h>
#include <stdlib.h>


typedef struct{
   char *ch;       //若串非空,则按串长分配存储区,
                   //否则ch为NULL
   int  length;    //串长度
}HString;

typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

Status InitString(HString *T) {
	(*T).length=0;
	(*T).ch=NULL;
	return OK;
}


Status ClearString(HString *S){
//将S清为空串
	if((*S).ch) {
		free((*S).ch); 
	}
	(*S).ch = NULL;
	(*S).length=0;
	return OK;
}//ClearString

Status StrAssign(HString *T,char *chars){

//*************补全代码*************
	int i = 0;
//	T->ch = (char*)malloc(100 *sizeof(char));
    int len = 0;
	for(; chars[len] != '\0'; len ++){}
		 
	T->ch = (char*)malloc(len *sizeof(char));
	for(;chars[i] != '\0';i ++)
	{
		(*T).ch[i] = chars[i];
	} 
	(*T).length = i;
	return OK;

}//StrAssign    


int StrLength(HString S){
//返回S的元素个数,称为串的长度
	return S.length;
}//StrLength

int StrCompare(HString S,HString T){
//若S=T,返回值=0;
	
	//*****补全代码********
	int i = 0;
	for(;i < S.length && i < T.length;i++)
	{
		if(S.ch[i] != T.ch[i])	return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
	

}//StrCompare    

Status StrInsert(HString *S,int pos,HString T){

 //*********补全代码***********
 	int i = 0;
 	if(pos > S->length + 1 || pos < 1)		return ERROR;
 	
 	for(i = S->length;i >= pos;i --)
 	{//将S->ch中第pos位及以后的总计S->length - pos + 1个字符往后移T->length个长度
 		S->ch[i + T.length - 1] = S->ch[i - 1];
	}
	for(i = 0;i < T.length ;i ++)
	{//将S->ch中第pos位及以后总计T->length个字符replace成T->ch中的字符
		S->ch[i + pos - 1] = T.ch[i];
	}
	S->length += T.length; //更新S->length
    S->ch[S->length] = '\0';  // 确保字符串以NULL结尾
	return OK;

	
}//StringInsert    


void StrTravel(HString S)
{
	int i;
	for(i=0;i<S.length;i++)
	{
		printf("%c",S.ch[i]);
	}
	printf("\n");
}

int main()
{
	HString S1,S2,S3;
	InitString(&S1);//初始化串1
	InitString(&S2);//初始化串2
	InitString(&S3);//初始化串3
	char str1[100],str2[100],str3[100];
	scanf("%s",str1);
	scanf("%s",str2);
	scanf("%s",str3);
	StrAssign(&S1,str1);//串1赋值
	StrAssign(&S2,str2);//串2赋值
	StrAssign(&S3,str3);//串3赋值
	int pos;
	scanf("%d",&pos);

	StrTravel(S1);
	StrTravel(S2);
	StrTravel(S3);
	if(StrInsert(&S1,pos,S2)==OK)//串插入
	{
		StrTravel(S1);//串打印输出
	}
	else
	{
		printf("insert fail\n");
	}
	int cmp = StrCompare(S1,S3);
	if(cmp == 0)
		printf("equal\n");
	else
		printf("not equal\n");
	ClearString(&S1);
	ClearString(&S2);
	ClearString(&S3);
	return 0;
}

