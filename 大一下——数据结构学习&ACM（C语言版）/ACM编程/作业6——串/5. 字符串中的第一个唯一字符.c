#include <stdio.h>
#include <string.h>

#define MAXSTRLEN 300000
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OK 1

typedef char SString [MAXSTRLEN + 1]; 

void StrAssign(SString S,char*str)
{
	int i = 1;
	for(;str[i - 1] != '\0';i ++)
	{
		S[i] = str[i - 1];
	}
	S[0] = i - 1;
	S[i] = '\0';
}

//int Unique_Index(SString S)
//{
//	if(S[0] == 0)	return -1;
//	int i,j,tag;
//	for(i = 1;i <= S[0];i ++)
//	{
//		for(j = 1;j <= S[0];j ++)
//		{
//			tag = -1;
//			if(j == i)	continue;	
//			else if(S[i] == S[j])	break;
//			if(S[i] != S[j])	tag = i;
//		}
//		if(tag != -1)	return i - 1;
//	}
//	return -1;
//}

int Unique_Index (SString S)
{
	if(S[0] == 0)	return -1;
	int i = 1;
	int char_count [256] = {0};
	for(;i <= S[0]; i++)
	{
		char_count[(int)S[i]] ++; 
	}
	for(i = 1;i <= S[0];i ++)
	{
		if(char_count[(int)S[i]] == 1)
		{
			return i - 1;
		}
	}
	return -1;
}

int main(int argc, char *argv[]) 
{
	char str[MAXSTRLEN + 1];
	scanf("%s",str);
	
	SString S;
	StrAssign(S,str);
	
	int a = Unique_Index(S);
	printf("%d",a); 
	
	return 0;
}
