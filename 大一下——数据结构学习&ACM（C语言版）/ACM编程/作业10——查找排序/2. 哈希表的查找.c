#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR -1

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如TRUE等 */

#define ITEMNO 12
#define HASHSIZE 13 // 定义哈希表长为数组的长度
#define NULLKEY -32768 // 空关键字

typedef struct{
    int* elem; // 数据元素存储基址，动态分配数组
    int count; //  当前数据元素个数
}HashTable;

Status initHashTable(HashTable* hash)
{
    int i;
    hash->count = 0;
    hash->elem = (int*)malloc(HASHSIZE * sizeof(int));
    if(!hash->elem)
        return ERROR;
    for (i = 0; i < HASHSIZE; i++)
        hash->elem[i] = NULLKEY;
    return OK;
}

// 构造哈希函数
int hashFun(int key)
{
    return key % HASHSIZE; // 构造方法为除留余数法
}

// 插入关键字进哈希表
int InsertHash(HashTable* hash, int key)
{
    int addr = hashFun(key); // 求哈希地址
    while (hash->elem[addr] != NULLKEY) // 如果不为空，则冲突
    {
        addr = (addr + 1) % HASHSIZE; // 开放定址法的线性探测
        if (addr > HASHSIZE)
            return ERROR;
    }

    hash->elem[addr] = key; // 直到有空位后插入关键字
    hash->count++;
    return OK;
}
/* 搜索哈希表函数定义，要求：
 * 函数接口定义为：Status SearchHash(HashTable hash, int key, int &addr)
 * 输入参数：hash 待搜索哈希表，key 目标关键字， addr 目标关键字在哈希表中的存储位置
 * 处理规则及返回值：按照线性探索方式查找key在哈希表中的位置。
 *                查找成功返回OK，不成功返回ERROR*/
Status SearchHash(HashTable hash, int key, int *addr)
{
    int ad = hashFun(key), i = 0;
	for(i = 0; i < HASHSIZE; i ++)
	{
		ad = (ad + i) % HASHSIZE;
		if(hash.elem[ad] == key)	
		{
			*addr = ad ;
			return OK;
		}
	 } 
    
    return ERROR;
    //将该函数补充完整
    
    
}

int main()
{
    int arr[HASHSIZE] = { 12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34 };
    int key;
    int addr;
    int i;
    HashTable hash;
    //初始化哈希表
    initHashTable(&hash);
    //插入关键字到哈希表
    for (i = 1; i <= ITEMNO; i++)
    {
        if (ERROR == InsertHash(&hash, arr[i-1]))
            printf("Item No %d is already exist.\n", i);
    }
    scanf("%d", &key);
    if (ERROR != SearchHash(hash, key, &addr))
        printf("The hash address of %d is %d.\n", key, addr);
    else
        printf("%d is not in the table.\n", key);

    return 0;
}
