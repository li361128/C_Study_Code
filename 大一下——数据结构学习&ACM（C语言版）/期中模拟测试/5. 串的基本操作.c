#include "stdio.h"

#include "string.h"

#define Main_str_len 10

#define Sub_str_len 5

typedef unsigned char SString[Main_str_len+1];

int StrAssign(SString T,char *chars)

{

       //学生补充完整
		int i = 1;
	   for(;chars[i - 1] != '\0';i ++)
	   {
	   		T[i] = chars[i - 1];
		} 
		T[0] = i - 1;
		T[i] = '\0'; 
		return 1;
}

int MySubStrIndex(SString T, SString sub, int pos)

{
	
//	if(pos >= 1 && pos <= S[0])
//    {
//        int i = pos;
//        int j = 1;
//        while(i <= S[0] && j <= T[0])
//        {
//            if(S[i] == T[j])
//            {
//                ++i;++j;
//            }
//            else
//            {
//                i = i - j + 2;
//                j = 1;
//            }
//        }
//        if(j > T[0])    return i - T[0];//返回 离pos 的距离
//        else return 0;
//    }
//    else return 0;

       //学生补充完整
       if(pos < 1 || pos >T[0])	return 0;
       int i = pos;
       int j = 1;
       while(i <= T[0] && j <= sub[0])
       {
       		if(T[i] == sub[j])
       		{
       			i ++;
       			j++;
			}
			else
			{
				i = i - j + 2;
				j = 1;
			}
	   }
	   if(j > sub[0])	return i - sub[0];
    	else return 0;

}

int MyStrInsert(SString T, int pos, SString sub)

{

       //学生补充完整
       int i = 0;
       for(i = 0;i < T[0] - pos + 1;i ++)
       {
       		T[T[0] + sub[0] - i] = T[T[0] - i];
	   }
       for(i = 0;i < sub[0];i ++)
       {
       		T[pos + i + 1] = sub[i + 1];
	   }
	   T[0] += sub[0];
	   T[T[0] + sub[0] + 1] = '\0';
	   return 1;

}

int StrDelete(SString T,int pos,int len)

{

       //从串S中删除第pos个字符起长度为len的子串，学生补充
       int i = 0;
       for(;i < T[0] - len;i ++ )
       {
       		T[i + pos] = T[i + pos + len ];
	   }
	   T[T[0] - len + 1] = '\0';
	   T[0] = T[0] - len;
	   return 1;

}

int StrEmpty(SString T)

{

       if(T[0]==0)

       {

              return 1;

       }

       return 0;

}

int StrLength(SString T)

{

       return T[0];

}

int Replace(SString T,SString S,SString V)

{   

   // 用V替换主串T中出现的所有与S相等的不重叠的子串

   int i=1;  // 从串S的第一个字符起查找串T

   if(StrEmpty(T))

          return 0; // T是空串

   do{

               i = MySubStrIndex(T,S,i); // 结果i为从上一个i之后找到的子串T的位置

               if(i)

               {

                 // 串S中存在串T

                 StrDelete(T,i,StrLength(S)); // 删除该串T

                 MyStrInsert(T,i,V);  // 在原串T的位置插入串V

                 i+=StrLength(V); // 在插入的串V后面继续查找串T

               }

   }while(i);

   return 1;

}

int StrCompare(SString T,SString S)

{

       //学生补充完整
       int i = 1;
       for(;i <= T[0] && i <= S[0];i ++)
       {
       		if(T[i] != S[i])	return T[i] - S[i];
	   }
	   return T[0] - S[0];

}

int main()

{

       int i;

       int res;

       int index;

       int pos;

       int len;

       int delpos;

       SString T={0};

       SString S={0};

       SString V={0};

       char input1[Main_str_len];

       char input2[Sub_str_len];

       char input3[Sub_str_len];

       printf("输入主串和子串\n");

       scanf("%s %s %s",input1,input2,input3);

       StrAssign(T,input1);

       StrAssign(S,input2);

       StrAssign(V,input3);     

       res=StrCompare(T,S);

       if(res>0)

       {

              printf("T串大于S串");

       }

       else if(res<0)

       {

              printf("T串小于S串");

 

       }else if(res==0)

       {

              printf("T串等于S串");

       }

       printf("\n");

       index=MySubStrIndex(T,S,1);

       printf("子串在主串中的位置是:%d\n",index);

       scanf("%d",&pos);

       MyStrInsert(T,pos,S);

       printf("打印插入子串后的元素\n");    

       for(i=1;i<=T[0];i++)

       {

              printf("%c ",T[i]);

       }

       printf("\n");

       printf("输入删除元素的位置和长度\n");

       scanf("%d %d",&delpos,&len);

       StrDelete(T,delpos,len);

       printf("删除后的元素为\n");

       for(i=1;i<=T[0];i++)

       {

              printf("%c ",T[i]);

       }

       printf("\n");

       printf("将主串中的子串S，全部替换为V\n");

       Replace(T,S,V);

       for(i=1;i<=T[0];i++)

       {

              printf("%c ",T[i]);

       }

       printf("\n");

       return 1;

}
