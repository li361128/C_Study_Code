#include <stdio.h>
#include <string.h>
#define MAXSTRLEN 100
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OK 1

typedef char SString[MAXSTRLEN + 1];

void StrAssign(SString S, char* str) {
    int i = 0;
    for(; str[i] != '\0'; i++) {
        if (str[i] == '#') break;
        S[i + 1] = str[i];
    }
    S[0] = i;
    S[i + 1] = '\0';
}

int StrConcat(SString S, SString T) {
    if (S[0] + T[0] > MAXSTRLEN) {
        return ERROR;
    }
    int i;
    for (i = 1; i <= S[0]; i++) {
        T[T[0] + i] = S[i];
    }

    T[0] += S[0];
    T[T[0] + 1] = '\0';

    return OK;
}

int main(int argc, char *argv[]) {
    int n = 100000, i;
    char str1[n],str2[n]; 
    
    // 读取两个字符串，以 '#' 结束
    scanf("%[^#]#", str1);
    getchar();  // 读取并丢弃换行符
    scanf("%[^#]#", str2);
    
//    printf("%s\n", str1);
//    printf("%s\n", str2);
     
    SString S, T;
    StrAssign(S, str1);
    StrAssign(T, str2);

    StrConcat(S, T);

    for (i = 1; i <= T[0]; i++) {
        printf("%c", T[i]);
    }
    printf("\n");
    return 0;
}

