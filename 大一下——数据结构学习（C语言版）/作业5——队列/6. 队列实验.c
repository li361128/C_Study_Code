#include <stdio.h>
#include "stdlib.h"
#include <malloc.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE -2

/*定义队列节点结构体类型、和队列节点结构体指针类型*/ 
typedef struct QUEUE_NODE 
{ 
	int data;
	struct QUEUE_NODE *next; 
//    补充完整
} QUEUE_NODE, *QUEUE_NODE_PTR; 

/*队列结构体类型、和队列结构体指针类型定义，包括：
  队列真实长度；
  队头位置指针；
  队尾位置指针*/ 
typedef struct 
{ 
    int Len; 
    QUEUE_NODE_PTR front;
    QUEUE_NODE_PTR rear;
//    补充完整
} LINK_QUEUE, *LINK_QUEUE_PTR; 

/*队列初始化函数，要求生成头结点，并将队列头指针、尾指针和长度正确赋值*/ 
int InitQueue(LINK_QUEUE *q) 
{  
	q->front = (QUEUE_NODE_PTR)malloc(sizeof(QUEUE_NODE));
	if(!q->front) return ERROR;
	q->rear = q->front;
	q->rear->next = NULL;
	return OK;
//    补充完整
    return 1; /*初始化成功返回1*/ 
} 

/*.队列判空函数，要求：
函数接口定义为：int IsQueueEmpty(LINK_QUEUE *q)；
2.输入参数：待判空队列q；
3 处理规则及返回值：通过队列长度元素判空。
                     队列为空返回1；队列非空返回0.*/
int IsQueueEmpty(LINK_QUEUE *q) 
{ 
	return ((q->Len == 0)?1:0); 
//    补充完整
}

/*.入队列函数，要求：
1.函数接口定义为：int EnQueue(LINK_QUEUE *q, int MRN)；
2.输入参数：待操作队列名q，待入队列数值（病例号）MRN；
3 处理规则及返回值：从内存堆中申请一个队列结点大小的存储空间作为新的队列结点newNode，给节点数据域赋值MRN，指针域为空。
    将队列队尾结点的指针域指向新节点newNode，队尾指针指向新节点newNode。
    入队列成功时返回1，入队列失败时返回0.*/
int EnQueue(LINK_QUEUE *q, int MRN) 
{ 
	QUEUE_NODE_PTR p ;
	p = (QUEUE_NODE_PTR)malloc(sizeof(QUEUE_NODE));
	if(!p)	return ERROR;
	p->data = MRN;
	p->next = q->rear->next;
	q->rear->next = p;
	q->rear = q->rear->next;
	q->Len ++;
	return OK;
//    补充完整
} 
 

/*.出队列函数，要求：
.函数接口定义为：int DeQueue(LINK_QUEUE *q)；
2.输入参数：待操作队列q；
3 处理规则及返回值：取队头节点，将其数据域数值作为返回值输出。
                     删除队头结点，并将头节点的next指针指向新的队头节点；
                     当出队列失败时返回0；成功时返回原队头结点的数据域数值。*/
int DeQueue(LINK_QUEUE *q) 
{  
	if(IsQueueEmpty(q))	return ERROR;
    int mn;
    QUEUE_NODE_PTR p = q->front->next;
    mn = p->data;
    q->front->next = q->front->next->next;
	if(p == q->rear ) q->rear = q->front;
	q->Len --;
	free(p);	 
//    补充完整
    return mn;//返回原队头结点的病历号 
} 

/*.销毁队列函数，要求：
函数接口定义为：int DestroyQueue(LINK_QUEUE *q)
2.输入参数：待销毁队列q；
3 处理规则及返回值：在队尾指针的辅助下，从头至尾逐一释放队列结点空间。
                     销毁成功返回1；否则，返回0.*/
int DestroyQueue(LINK_QUEUE *q) 
{ 
    /*一般防护：如果队列不存在，返回错误*/ 
    if(q->front == NULL) 
    { 
        return 0; 
    } 
    /*在队尾指针的辅助下，从头至尾逐一释放队列结点空间*/
    while(q->Len)
    {
    	DeQueue(q);
	}
	q->front = q->rear = NULL; 
    
//    补充完整
    return 1; 
} 

/*.队列遍历函数，要求：
.函数接口定义为：int QTraverse(LINK_QUEUE *q)
2.输入参数：进行遍历的队列q；
3 处理规则及返回值：从首至尾遍历队列，依次打印输出所有队列结点数据域数值。数值之间间隔一个制表符位置；
                     遍历成功返回1；队列不存在或为空返回0*/
int QTraverse(LINK_QUEUE *q) 
{ 
    QUEUE_NODE_PTR p; 
    /*队列不存在或为空返回0*/ 
    if(q->front == NULL || q->Len == 0) 
    { 
        return 0; 
    } 
    /*从队列第一个元素开始遍历队列，依次打印输出所有队列结点数据域数值，每次循环结束p后移一个节点*/ 
    for(p=q->front->next; p!=NULL; p= p->next) 
    { 
        printf("%d\t", p->data); 
    } 
    return 1; 
} 

/**************************************************************************/ 
/*                                                                        */ 
/**************************************************************************/ 

int main() 
{ 
    LINK_QUEUE QPatient ={0};//定义病人队列 
    int flag = 1; /*上下班标志位： 1为上班，0为下班*/ 
    int Medical_Record_NO = 0; 
    char ch = 0; 
    char a[100];
    int length;
    int index;
    //初始化病人对列 
    InitQueue(&QPatient); 
    //输入处理命令 
    gets(a); 
    length = strlen(a); 
    index = 0; 
    /*上班时，依次处理各个输入命令*/ 
    while( (flag==1) && (index<length) ) 
    { 
        ch = a[index] &0xff; /*从控制台接收命令*/ 
        index++; 
        switch (ch) 
        { 
            case 'a': 
                /*新增病人排至队尾*/ 
                Medical_Record_NO=Medical_Record_NO+1;  /*记录病人数量*/
                EnQueue(&QPatient, Medical_Record_NO); 
                printf("\nYour patient's No. is:%d.\t", Medical_Record_NO); 
                printf("There are %d patient(s) waiting ahead of you.", QPatient.Len); 
                break; 
            case 'n': 
                /*队头病人出队看病*/ 
                if(!IsQueueEmpty(&QPatient)) 
                { 
                    Medical_Record_NO = DeQueue(&QPatient); 
                    printf("\nPatient No. %d, please go to the clinic", Medical_Record_NO); 
                } 
                else 
                { 
                    printf("\n No patient is waiting in line.\n"); 
                } 
                break; 
            case 'q': 
                /*下班：如果队列中还有病人则依次出队，否则打印hello*/ 
                if(!IsQueueEmpty(&QPatient)) 
                { 
                    printf("\nIt is the end of today. Following patients please go to the clinic in turn: "); 
                    QTraverse(&QPatient); 
                    printf("\n"); 
                } 
                else 
                {                    
                    printf("hello\n"); 
                } 
                flag = 0;//置下班标志 
                //销毁队列 
                DestroyQueue(&QPatient); 
                break; 
            default: 
                printf("ERROR\n"); 
                break; 
        }// end of switch(ch) 
    }//end of while() 
    return 0; 
} 

