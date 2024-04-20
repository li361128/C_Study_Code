#include <stdio.h>
#include <string.h>

#define MAXSTRLEN 100
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OK 1

typedef char SString[MAXSTRLEN + 1];

void SStringAssign(SString S,char*str)
{
	int i = 1,len = 0;
	for(;str[len] != '\0';len ++)
	for(;str[i - 1] != '\0';i ++)
	{
		S[i] = str[i - 1];
	}
	S[0] = len;
	S[len + 1] = '\0'; 
}

void CountStr(SString S,int *total)
{
	int i = 1;
	for(;i <= S[0];i ++)
	{
		total[S[i] - 'a'] ++;
	}
}

void PrintMax(int *total)
{
	int max = total[0],i = 0,max_n = 0;
	for(;i < 26;i ++)
	{
		if(max < total[i])
		{
			max = total[i] ;
			max_n = i;
		}
	}
	printf("%c %d\n",max_n + 'a',max);
}

int main(int argc, char *argv[]) 
{
	int n ;
	scanf("%d",&n);
	getchar();
	while(n --)
	{
		SString S;
		char str[MAXSTRLEN + 1000];
		scanf("%s",str); 
        str[100] = '\0';
		getchar();
		//printf("%s",str); 
		SStringAssign(S,str);
		
		int total[26] = {0};
		CountStr(S,total);
		
		PrintMax(total);			
	} 
	return 0;
}
