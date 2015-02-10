#include <stdio.h>
// 交换两个整型的值
void swap(int *x, int *y)
{
	int tmp=0;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

//遍历打印数组a的前n个数
void print_a(int a[], int n)
{
	int i=0;
	for (i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}