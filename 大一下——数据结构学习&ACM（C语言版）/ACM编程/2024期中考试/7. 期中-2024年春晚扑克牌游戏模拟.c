#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;

// 定义扑克牌结构

typedef struct {
    char suit[10];   //花色： "Hearts", "Diamonds", "Clubs", "Spades"
    char face[10];   //面值： "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" 
} Card, QElemType, SElemType;


typedef struct Lnode{
	SElemType data;
	struct Lnode *next;
	
}LNode,*LinkList;

typedef struct{
	LinkList Head;
	int length;
	
}LinkStack;

Status InitLinkStack(LinkStack *S)
{
	S->Head = (LinkList)malloc(sizeof(LNode));
	if(!S->Head)
		return ERROR;
	
	S->Head->next = NULL;
	S->length = 0;
	
	return OK;
} 


Status StackEmpty(LinkStack S)
{
	return (S.Head->next == NULL);
	
}

Status Push(LinkStack *S, SElemType e)
{
	LinkList p;
	
	p = (LinkList)malloc(sizeof(LNode));
	if(!p)
		return ERROR;
	
	p->data = e;
	p->next = S->Head->next;
	S->Head->next = p;
	S->length++;
	
	return OK;
	
}

Status GetTop(LinkStack S, SElemType *e)
{
	if(!S.Head->next )
		return ERROR;
	
	*e = S.Head->next->data;
	
	return OK;
	
}

Status Pop(LinkStack *S, SElemType *e)
{
	
	LinkList p;
	
	p = S->Head->next;
	
	if(!p)
		return ERROR;

	*e = p->data;
	
	S->Head->next = p->next;
	free(p);
	
	S->length--;
	
	return OK;
	
}

int StackLength(LinkStack S)
{
	return S.length;
	
}


#define MAXQSIZE  10   //最大队列长度
typedef struct {
   QElemType *base;   //初始化的动态分配存储空间
   int  front;                    //头指针   
   int  rear;                     //尾指针
}SqQueue;  


char suits[4][10] = {"Hearts", "Diamonds", "Clubs", "Spades"};
char faces[13][10] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

Status InitQueue (SqQueue *Q){
   //构造一个空队列Q
   Q->base=(QElemType *) malloc(MAXQSIZE *sizeof(QElemType)); 
   if(!Q->base) return ERROR;
   Q->front=Q->rear=0;
   return OK;
}//InitQueue

Status QueueEmpty (SqQueue Q){
    return (Q.front==Q.rear);                             
}// QueueEmpty

Status EnQueue(SqQueue *Q,QElemType e){
    if((Q->rear+1)%MAXQSIZE==Q->front)  return ERROR;//队列满
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXQSIZE;
     return OK;
}//EnQueue

Status DeQueue (SqQueue *Q,QElemType *e){
   if(Q->front==Q->rear) return ERROR;
   *e=Q->base[Q->front];
   Q->front=(Q->front+1)%MAXQSIZE;
   return OK;
}//DeQueue

Status QueueTraverse(SqQueue Q,void(*vi)(QElemType))
{ /* 从队头到队尾依次对队列Q中每个元素调用函数vi().一旦vi失败,则操作失败 */
   int i;
   i=Q.front;
   while(i!=Q.rear)
   {
     vi(*(Q.base+i));
     i=(i+1)%MAXQSIZE;
   }
   printf("\n");
   return OK;
}

/* prepare card */
void prepare_card(LinkStack *S, char suit, int face)
{
  
//***补全代码****  
	if(face > 13 || face < 1 || suit != 'H' || suit != 'D' || suit != 'C' || suit != 'S' )
	{
		printf("Illegal suit input");
		exit(-1);
		 }	 
	
  
  
}
/* expand cards */
void expand_card(SqQueue *Q)
{

//***补全代码****


}
/* shuffle cards */
void shuffle_card(SqQueue *Q, int num){

    int i;
    QElemType e;
    for(i=0; i<num; i++){
        DeQueue(Q, &e);
        EnQueue(Q, e);
    }

}

/* insert first k cards into bottom after pos  */
void insert_card(SqQueue *Q, int k, int pos)
{

//***补全代码****


}


// print card
void printCard(Card card) {
    if(card.face[1]=='0')
        printf("[%c-%c%c]", card.suit[0], card.face[0], card.face[1]);
    else
        printf("[%c-%c]", card.suit[0], card.face[0]);
}

int main() {
    int i;
    char suit;  /* 存储扑克花色的首字母  */
    int face;  /* 存储扑克牌的分值, 分值为1~13 */
    int pos; /* 存储第3步插入那张牌后面 */
    int name; /* 名字字数 */
    int gender;  /* 存储扔掉牌数量：男生1 或女生 2 */
    Card card, secret;

    SqQueue Q; /* 存储扑克牌堆 */
    LinkStack S;
    InitQueue(&Q);
    InitLinkStack(&S);
/* 1. 拿出4张扑克牌并随意打乱顺序； */
/* 根据输入的数字和花色抽取4张牌，完成第1步 */
    // printf("Please input 4 card suit and face (example: H-3):\n");
    for(i=0; i<4; i++) {
        /* 顺序输入4章扑克牌的花色和分值和，花色在后;分值在前 */
        scanf("%c-%d", &suit, &face);
        getchar();
        prepare_card(&S, suit, face);
    }

    for(i=0; i<4; i++){
        Pop(&S, &card);
        EnQueue(&Q, card);
    }
    printf("After 1-step process:\n");
    QueueTraverse(Q, printCard);
/* 2. 撕开扑克牌重叠放在一起； */    
    expand_card(&Q);
    printf("After 2-step process:\n");
    QueueTraverse(Q, printCard);

/* 3.根据名字字数循环扑克n次；*/
    // printf("Please input the length of your name: ");
    scanf("%d", &name);
    shuffle_card(&Q, name);
    printf("After 3-step process:\n");
    QueueTraverse(Q, printCard);
/* 4. 将最上面的3张扑克牌随机插入下面的扑克牌中间； */
    // printf("Please input the 1-st insert position(3<k<n): ");
    scanf("%d", &pos);
    insert_card(&Q, 3, pos);
    printf("After 4-step process:\n");
    QueueTraverse(Q, printCard);
/* 5.将最上面的扑克牌最为谜底保存起来； */ 
    DeQueue(&Q, &secret);
    printf("After 5-step process:\n");
    QueueTraverse(Q, printCard);
/* 6.将最上面的3张扑克牌随机插入下面的扑克牌中间； */    
    // printf("Please input the 2nd insert position(3<k<n): ");
    scanf("%d", &pos);
    insert_card(&Q, 3, pos);
    printf("After 6-step process:\n");
    QueueTraverse(Q, printCard);
/* 7. 根据男生或者女生，将最上面的扑克牌扔出去1张或者2张； */
    // printf("Please input your gender(male:1, fename:2): ");
    scanf("%d", &gender);
    DeQueue(&Q, &card);
    if(gender==2)
        DeQueue(&Q, &card);
    printf("After 7-step process:\n");
    QueueTraverse(Q, printCard);
/* 8. “见证奇迹的时刻”，将扑克牌循环7次 */
    shuffle_card(&Q, 7);
    printf("After 8-step process:\n");
    QueueTraverse(Q, printCard);
/* 9. “好运留下来，烦恼丢出去”，循环一次丢弃一次 */
    while((Q.rear-Q.front+MAXQSIZE)%MAXQSIZE != 1){
        shuffle_card(&Q, 1);
        DeQueue(&Q, &card);
        // QueueTraverse(Q, printCard);
    }

    DeQueue(&Q, &card);
    printf("Final 9-step process:\n");
    printCard(card);
    printf("\n");
    printf("Secrete card:\n");
    printCard(secret);
    printf("\n");
    return 0;
}

