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
      printf("请输入五个年龄，以逗号隔开\n");
       int AGE[5];
      //输入5个年龄
      scanf("%d,%d,%d,%d,%d",&AGE[0],&AGE[1],&AGE[2],&AGE[3],&AGE[4]);
      struct STUDENT (*p_stu)[5]=(struct STUDENT (*)[5])malloc(5*sizeof(struct STUDENT));
	//struct STUDENT (*p_stu)[5]表示的是指向一个元素为5的struct STUDENT数组的指针 

	//在此处添加一个for循环，使用p_stu指针将数组AGE的值依次（从AGE[0]到AGE[4]）赋值给结构体的STU_AGE字段

		int i;
       for(i=0;i<5;i++)
       {
			p_stu[i]->STU_AGE = AGE[i];      
       		printf("%d\n",p_stu[i]->STU_AGE);
       }
       return 0;
}
