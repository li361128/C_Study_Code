//========================================================
//     代码框架 C语言版
//========================================================

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEVEL 4  /*跳表最大层数*/
typedef struct skip_list_node
{
	int key;    /*key是唯一的*/
	int value; 	/*存储的内容*/
	int level; 	/*当前节点最大层数*/
	/*指针数组,根据该节点层数的不同分配大小不同的数组
	 *next[0]表示该节点的第一层下一节点的地址
	 *next[1]表示该节点的第二层下一节点的地址
	 *next[n]表示该节点的第n层下一节点的地址
	 */
	struct skip_list_node *next[];
} skip_list_node;

typedef struct skip_list
{
	int level; /*跳表层数*/
	int num;   /*节点数目*/
	struct skip_list_node *head;
} skip_list;

/**
 * 生成表节点.
 * 
 * 返回：
 *  NULL:内存申请失败
 * !NULL:节点创建成功
 */
static skip_list_node* skip_list_node_creat(int level, int key, int value)
{
	struct skip_list_node *node = NULL;
	
	/* 节点空间大小 为节点数据大小+ level层索引所占用的大小 */
	node = (skip_list_node*)malloc(sizeof(skip_list_node) + level * sizeof(skip_list_node*));
	if (node == NULL)
		return NULL;
	
	/* 赋值 */
	node->key = key;
	node->value = value;
	node->level = level;
	int i;
    for(i=0; i<level; i++)
    {
    	 node->next[i] = NULL;
	}	
	return node;
}

/**
 * 跳表初始化.
 * 输入
 * level:跳表最大层数
 * 返回
 * -1 :创建失败
 *  0 :创建成功
 */
int skip_list_init(skip_list *L, int level)
{	
	L->level = level;
	L->num = 0;
    // L->head =(skip_list_node*)malloc(sizeof(skip_list_node)+(level)*sizeof(skip_list_node*));
    L->head = skip_list_node_creat(level, 0, 0);
	if (L->head == NULL)
	{
		return -1;
	}
	return 0;
}

/**
 * 插入跳表节点.
 * 输入：
 * list:跳表
 * key:
 * value:
 * 返回 -1:跳表为空
 *     -2:空间分配失败
 *     -3:key已经存在
 *      0:插入成功
 */
int skip_list_insert(struct skip_list *list, int level, int key, int value)
{
	struct skip_list_node **update = NULL; /*用来更新每层指针，存放插入位置的前驱各层节点*/ 
	struct skip_list_node *cur = NULL;
	struct skip_list_node *prev = NULL;
	struct skip_list_node *insert = NULL;
	int i = 0;
	
	if (list == NULL || level <0 || level > MAX_LEVEL)
		return -1;
	
	/*申请update空间用于保存每层的但插入位置前驱节点*/
	update = (skip_list_node **)malloc(list->head->level * sizeof(struct skip_list_node *));
	if (update == NULL)
		return -2;
	
	/*逐层查询,查找插入位置的前驱各层节点索引
	 *update[0] 存放第一层的插入位置前驱节点，update[0]->next[0]表示插入位置的前驱节点的下一节点(update[0]->next[0])的第一层索引值
	 *update[1] 存放第二层的插入位置前驱节点，update[1]->next[1]表示插入位置的前驱节点的下一节点(update[1]->next[0])的第二层索引值
	 *update[n] 存放第一层的插入位置前驱节点，update[n]->next[n]表示插入位置的前驱节点的下一节点(update[n]->next[0])的第n层索引值
	 */
	prev = list->head; /*从第一个节点开始的最上层开始找*/
	i = list->level - 1;
	for(; i>=0; i--)
	{
		/* 各层每个节点的下一个节点不为空 && 下个节点的key小于要插入的key */
		while ( ((cur = prev->next[i]) != NULL) && (cur->key < key) )
		{
			prev = cur; /* 向后移动 */
		}
		update[i] = prev; /* 各层要插入节点的前驱节点 */
	}
	
	/* 当前key已经存在,返回错误 */
	if ((cur != NULL) && (cur->key == key))
	{
		return -3;
	}
	
	/*创建当前节点*/
	insert = skip_list_node_creat(level, key, value);
	/*根据最大索引层数,更新插入节点的前驱节点,前面已经更新到了[0] - [(list->level-1)]*/
	if (level > list->level)
	{
		for (i=list->level; i<level; i++)
		{
			update[i] = list->head;/*这部分为多新增的索引层,所以前驱节点默认为头结点*/
		}
		list->level = level;/*更新跳表的最大索引层数*/
	}
	
	/*逐层更新节点的指针*/
	for (i=0; i<level; i++)
	{
		insert->next[i] = update[i]->next[i];
		update[i]->next[i] = insert;
	}
	
	/*节点数目加1*/
	list->num++;
	
	return 0;
}

/**
 * 查询当前key是否在跳表中,存在返回查询的value数值.
 * 
 * list:跳表
 * key: 查询的key
 * value:查询的数据
 * 返回值 -1:跳表为空 或 跳表节点数量为0
 *         -3:key不存在
 *          0:查找成功
 */
int skip_list_search(skip_list *list, int key, int *value)
{
	
	//★★★请补全代码

	struct skip_list_node *cur = NULL;
	struct skip_list_node *prev = NULL;

	int i = 0;
	
	if (list == NULL || list->num == 0)
		return -1;
	
	prev = list->head; /*从第一个节点开始的最上层开始找*/
	i = list->level - 1;
	for(; i>=0; i--)
	{
		/* 各层每个节点的下一个节点不为空 && 下个节点的key小于要插入的key */
		while ( ((cur = prev->next[i]) != NULL) && (cur->key < key) )
		{
			prev = cur; /* 向后移动 */
		}
	}
	 if (cur->key == key)
	{
		*value = cur->value;
		return 0;
	}
	
	return -3;
}

/* 打印level层所有元素 */
void display(skip_list *list, int level)
{
    skip_list_node *cur;
    if (list == NULL && list->num == 0)
        return;
    if (level<0 || level > list->level)
        return;
    cur = list->head->next[level];
    while(cur)
    {
        printf("%d:%d\n", cur->key, cur->value);
        cur = cur->next[level];
    }
}

int main()
{
    skip_list list;
    int key;
    int value;
    int level;
    int i;
    
    skip_list_init(&list, MAX_LEVEL);
    scanf("%d%d%d", &level, &key, &value);
    while(level>0 || level>MAX_LEVEL)
    {
        skip_list_insert(&list, level, key, value);
        scanf("%d%d%d", &level, &key, &value);
    }
    printf("the number of nodes is %d\n", list.num);
    for(i=0; i<MAX_LEVEL; i++)
    {
        printf("the node of level %d\n", i);
        display(&list, i);
    }
    scanf("%d", &key);
    int res = skip_list_search(&list, key, &value);
    if(res == -1)
        printf("skip list is empty\n");
    else if(res == -3)
        printf("key not found\n");
    else
        printf("key found %d:%d\n", key, value);

    return 0;
}
