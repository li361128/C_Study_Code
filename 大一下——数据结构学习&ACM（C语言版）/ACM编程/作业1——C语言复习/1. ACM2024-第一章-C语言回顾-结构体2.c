#include "stdio.h" 

#include "malloc.h" 

#include "string.h" 

 

struct STUDENT 

{ 

    char STU_ID[8]; 

    char STU_NAME[10]; 

    int STU_AGE; 

    int STU_SCORE; 

}; 

 

int main(int argc, char* argv[]) 

{ 

 

    struct STUDENT *stu1=(struct STUDENT *)malloc(sizeof(struct STUDENT)); 

    stu1->STU_AGE=12; 

    strcpy(stu1->STU_ID,"04120084"); 

    strcpy(stu1->STU_NAME,"张三");  

 

    struct STUDENT *stu2=(struct STUDENT *)malloc(sizeof(struct STUDENT));   

    stu2->STU_AGE=12; 

    strcpy(stu2->STU_ID,"04120085"); 

    strcpy(stu2->STU_NAME,"李四");  

 

printf("输入学生成绩\n");

 scanf("%d,%d",&(stu1->STU_SCORE),&(stu2->STU_SCORE));  

    //学生撰写程序至结束 

    //定义一个中间的结构体变量，进行交换 

    struct STUDENT *stu_it=(struct STUDENT *)malloc(sizeof(struct STUDENT)); 

 

    if(你来添加) 

    { 

        你来添加; 

        你来添加; 

        你来添加; 

    } 

     

    printf("%s,%d\n",stu1->STU_NAME,stu1->STU_SCORE); 

    printf("%s,%d\n",stu2->STU_NAME,stu2->STU_SCORE); 

} 


