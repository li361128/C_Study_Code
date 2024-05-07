#include <stdio.h>
#include <string.h>
#include<malloc.h>

#define MAXSTRLEN 255
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OK 1

int check(char *s, int x, int n,int *pos) 
{
	int j = 0,i,k;

	for(;j < n - x + 1;j ++)
	{
		char substr[x + 1];
		for(i = j,k=0;i < x + j; i ++,k++)
		{
			substr[k] = s[i];
		}
		substr[x] = '\0';
	    int count = 0;
		for (i = 0; i <= n - x; i++) 
		{
	        if (strncmp(s + i, substr, x) == 0) 
			{
	            count++;
	        }
	        if(count == 2)
	        {
	        	*pos = j;
	        	return 1;
			}
	    } 
	}
	return 0;
}

char *search_longest_repeated_substring(char *s, int n) {
    int l = 0, r = n,pos = 0;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (check(s, mid, n, &pos))    l = mid;
        else      r = mid - 1;
    }
    if (l == 0) {
        return NULL;
    }
    char *result;
	result = (char*)malloc((l + 1) * sizeof(char));
    if (result == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    strncpy(result, s + pos, l);
    result[l] = '\0';
    return result;
}

int main() {
    char *s = malloc(MAXSTRLEN * sizeof(char));
    if (s == NULL) 
	{
        printf("内存分配失败\n");
        return 1;
    }
    scanf("%s", s);

    char *result = search_longest_repeated_substring(s, strlen(s));
    
    if (result == NULL) 
	{
        printf("没有最长重复子串\n");
    }
	 else 
	 {
        printf("%s\n", result);
        free(result);
    }

    free(s);

    return 0;
}

