#include <stdio.h>
#include <stdlib.h>

//折半查找函数
//int a[ ]:查找表，int n: 查找表长度， int target: 待查找的元素
//如果查找成功，返回元素数组下标（从0开始），如果查找失败，返回-1
int BinarySearch(int a[ ],  int n,  int target) 
{
//★★★请补全代码
	int l = 0, r = n;
	while(l <= r)
	{
		int mid = (r + l) / 2;
		if(a[mid] < target)	l = mid + 1;
		else if(a[mid] == target)	return mid;
		else r = mid - 1; 
	 } 
	 return -1;

}

int main( )
 {
	int a[10], n, i, m;
        scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	scanf("%d", &m);
	
	int q;
	q = BinarySearch(a, 10, m);
	if (q != -1) {
		printf("%d", q + 1);
	}
	else {
		printf("not found");
	}
	return 0;
}
