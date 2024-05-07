#include <stdio.h>
#include <string.h>

#define MAIN_STR_LEN 100
#define SUB_STR_LEN 20

int MyStrCompare(char* Str1, char* Str2) 
{ 
    int i;
    int result = 0;
    for (i = 1; (i <= Str1[0]) && (i <= Str2[0]); i++) 
    {
        if (Str1[i] > Str2[i]) 
        {
            result = 1;
            break;
        } 
        else if (Str1[i] < Str2[i]) 
        {
            result = -1;
            break;
        } 
        else 
        {
            /* 这里可以写点什么？ */
        }
    }
    if(result==0) 
    {
        if (Str1[0] > Str2[0]) 
        {
            result = 1;
        } 
        else if (Str1[0] < Str2[0]) 
        {
            result = -1;
        } 
        else 
        {
            result = 0;
        }
    } 
    else 
    {
        /* 这里可以写点什么？*/
    }
    return result;
}

int MySubStrIndex(char* MainStr , char* SubStr , int pos) 
{
    int i, j, result;
    if ((pos < 0) || (pos > (MainStr [0] - SubStr[0] + 1))) 
    {
        result = 0;
    } 
    else 
    {
        i = pos;
        j = 1;
        while (i <= MainStr [0] && j <= SubStr [0]) 
        {
            if (MainStr[i] == SubStr[j]) 
            {
                i++;
                j++;
            } 
            else 
            {
                i = i - j + 2;
                j = 1;
            }
        }
        if (j > SubStr [0]) 
        {
            result = i - SubStr [0];
        } 
        else 
        {
            result = 0;
        }
    }
    return result;
}

char MyStrDelete(char* S, int pos , int len) 
{
    int i;
    if (pos <1 || pos >S[0] - len + 1 || len < 0)
        return -1;
    for (i = pos + len; i <= S[0]; i++)
        S[i - len] = S[i];
    S[0] -= len;
    return 1;
}

char MyStrInsert(char* S, int pos , char* T) 
{
    int i;
    if (pos <1 || pos >S[0] + 1)
        return -1;
    if (S[0] + T[0] <= MAIN_STR_LEN) 
    {
        for (i = S[0]; i >= pos; i--) 
        {
            S[i + T[0]] = S[i];
        }
        for (i = pos; i < pos + T[0]; i++) 
        {
            S[i] = T[i - pos + 1];
        }
        S[0] = S[0] + T[0];
        return 1;
    } 
    else 
    {
        for (i = MAIN_STR_LEN; i <= pos; i--) 
        {
            S[i] = S[i - T[0]];
        }
        for (i = pos; i < pos + T[0]; i++) 
        {
            S[i] = T[i - pos + 1];
        }
        S[0] = MAIN_STR_LEN;
        return 0;
    }
}

int MyStrAssign(char * StrTobeAssigned , char * StrInput)

{
	int len = 0,i = 1;
	for(;StrInput[len] != '\0'; len ++) 
	for(;StrInput[i - 1] != '\0';i ++)
	{
		StrTobeAssigned[i] = StrInput[i - 1];
	}
	StrTobeAssigned[0] = len;
	return 1;
}

int MyStrReplace(char * MainStr , char * SubStr1 , char * SubStr2)

{
	int i = 1,tot = 0;
	do 
	{
		i = MySubStrIndex(MainStr,SubStr1,i);
		if(i)
		{
			MyStrDelete(MainStr,i,SubStr1[0]);
			MyStrInsert(MainStr,i,SubStr2);
			i += strlen(SubStr2);
			tot ++;
		}
	 } while(i);
	 return tot;
}

int main() 
{
    char MainStr[MAIN_STR_LEN];
    char SubStr1[SUB_STR_LEN];
    char SubStr2[SUB_STR_LEN];
    int i;
    int compareResult;
    int pos;
    int replaceCounter = 0;
    char InputBuf[3][MAIN_STR_LEN];

    printf("please input 3 strings as MainStr , SubStr1 and SubStr2\n");
    scanf("%s %s %s", InputBuf[0], InputBuf[1], InputBuf [2]);

    MyStrAssign(MainStr, InputBuf[0]);
    MyStrAssign(SubStr1, InputBuf[1]);
    MyStrAssign(SubStr2, InputBuf[2]);

    printf("MainStr =:%d,", MainStr[0]);
    for (i = 1; i <= MainStr[0]; i++) 
    {
        printf("%c,", MainStr[i]);
    }
    printf("\n");
    printf("SubStr1 =:%d,", SubStr1[0]);
    for (i = 1; i <= SubStr1[0]; i++) 
    {
        printf("%c,", SubStr1[i]);
    }
    printf("\n");
    printf("SubStr2 =:%d,", SubStr2[0]);
    for (i = 1; i <= SubStr2[0]; i++) 
    {
        printf("%c,", SubStr2[i]);
    }
    printf("\n");

    compareResult = MyStrCompare(SubStr1, SubStr2);
    printf("SubStr1 compare with SubStr2 is %d\n", compareResult);

    pos = MySubStrIndex(MainStr, SubStr1, 1);
    printf("pos of SubStr1 in MainStr is %d\n", pos);

    pos = MySubStrIndex(MainStr, SubStr2, 1);
    printf("pos of SubStr2 in MainStr is %d\n", pos);

    replaceCounter = MyStrReplace(MainStr, SubStr1, SubStr2);
    printf("The content of MainStr after %d times of replacing SubStr1 with SubStr2 is :\n%d,", replaceCounter , MainStr[0]);
    for (i = 1; i <= MainStr[0]; i++) 
    {
        printf("%c,", MainStr[i]);
    }
    printf("\n");
    return 0;
}

