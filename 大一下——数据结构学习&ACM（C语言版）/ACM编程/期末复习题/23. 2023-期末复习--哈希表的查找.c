/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


#include <stdio.h>

#include <stdlib.h>

#define TRUE 1

#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如TRUE等 */

#define HASHSIZE 12 // 定义哈希表长为数组的长度

#define NULLKEY -32768 // 空关键字


typedef struct

{

int *elem; // 数据元素存储基址，动态分配数组

int count; //  当前数据元素个数

}HashTable;


int m = 0; // 哈希表表长，全局变量


Status initHashTable(HashTable *hash)

{

int i;

	m = HASHSIZE;

	hash->count = m;

	hash->elem = (int *)malloc(m*sizeof(int));

	for (i = 0; i < m; i ++)
		hash->elem[i] = NULLKEY;
	
	return TRUE;

}

// 构造哈希函数

int hashFun(int key)

{

return key % m; // 构造方法为除留余数法

}

// 插入关键字进哈希表

void insertHash(HashTable *hash, int key)

{

int addr = hashFun(key); // 求哈希地址

while (hash->elem[addr] != NULLKEY) // 如果不为空，则冲突

{

		addr = (addr + 1) % m; // 开放定址法的线性探测

}

	hash->elem[addr] = key; // 直到有空位后插入关键字

}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */


Status searchHash(HashTable hash, int key, int *addr)
{
	*addr = hashFun(key);
	while(hash.elem[*addr] != key && hash.elem[*addr] !=NULLKEY && (*addr + 1) != hashFun(key))
	{
		*addr = (*addr + 1) % m;
	}
	if(hash.elem[*addr] == key)
		return 1;
	return 0;
}



/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


int main()

{

int arr[HASHSIZE] = {12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34}; // 要插入关键字

int key; // 关键字

int addr; // 哈希地址

int i;

int result;

HashTable hash;

// 初始化哈希表

	initHashTable(&hash);

// 插入关键字到哈希表

for (i= 0; i< m; i++)

{

		insertHash(&hash, arr[i]);

}

// 遍历查找关键字（都会成功）

	printf("输入要查找的key值:\n");

	scanf("%d",&key);
	
//	printf("%d",key); 

	result=searchHash(hash, key, &addr);

if (result)

		printf("查找 %d 的哈希地址为：%d\n", key, addr);

else

		printf("查找 %d 失败\n", key);

return 0;

}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
