#include <stdio.h>   

#include <stdlib.h>   



#define ERROR 0

#define OK 1

#define TRUE 1

#define FALSE 0

#define MAXSIZE 20



typedef struct

{

    char *ch;       //若串非空,则按串长分配存储区

    int  length;    //串长度

}HString;



int InitString(HString *T) 

{

    T->ch=(char*)malloc(sizeof(char)*MAXSIZE);

    if(!T->ch)

        return ERROR;

    T->length=0;

    return OK;

}



//将字符数组chars赋值到串T

//如果操作成功，返回OK，否则返回ERROR

int StrAssign(HString *T,char *chars)

{

//★★★请补全代码
	int i = 0;
	for(;chars[i] !='\0';i++)
	{
	}
	if(!i)
	{
		T->ch = NULL;
		T->length = 0;
	}
	else
	{
		int j = 0;
		for(j = 0;chars[j] != '\0';j ++)
		{
			T->ch[j] = chars[j];
			T->length ++;
		}
		
	}
	return OK;


}



   

// 比较字符串大小

//（1）如果两个串长度相等，且每一个相应位置上的字符都一样，则结果为0；

//（2）如果两个串长度不相等，则则以第一个不相同的字符作为基准，返回第一个不相同的字符ASCII差值；

//（3）如果两个串长度不相等，且所有相应位置上的字符都一样，则返回两个字符串的长度之差。

int StrCompare(HString S,HString T)

{

  //★★★请补全代码
  int i = 0;
  while(i < S.length && i < T.length)
  {
  		if(S.ch[i] != T.ch[i])	return (S.ch[i] - T.ch[i]);
  		i++; 
  }
  return S.length - T.length;



}//StrCompare    



int main()

{

    HString S;

    HString T;

    char mainstr[20];

    char substr[10];

    int index;

    InitString(&S);

    InitString(&T);

    gets(mainstr);

    gets(substr);

    StrAssign(&S,mainstr);

    StrAssign(&T,substr);

    printf("%d\n",StrCompare(S,T));

    return 1;

}
