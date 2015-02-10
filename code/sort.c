#include <stdio.h>

#include "misc.h"

// 冒泡排序
static void bubble_sort(int a[], int n)
{
	int i = 0;
	int j = 0;
	for (i=0; i<n-1; i++)
	{
		// 比较相邻元素，若a[j]比a[j+1]大，则交换
		// a[j]就像一个气泡一样“浮”到合适位置了
		for(j=0; j<n-1-i; j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j], &a[j+1]);
			}
		}
	}
}

// 选择排序
static void select_sort(int a[], int n)
{
	int i=0,j=0,min=0;
	for (i=0; i < n-1; i++)
	{
		min = i;
		// 找到最小值
		for (j=i+1; j <= n-1; j++)
		{
			if (a[min] > a[j])
				min = j;
		}
		if(min != i)
		{
			swap(&a[min], &a[i]);
		}
	}
}

// 插入排序, 后移无序数据
static void insert_sort(int a[], int n)
{
	int i=0;
	int j=0;
	int tmp=0;
	for (i = 1; i < n; i++)
	{
		// 取牌
		tmp = a[i];
		// 往前插的起始位置
		j = i - 1;

		// 大的a[j]都放后面，寻找出j
		while ((j >= 0) && a[j] > tmp)
		{
			// 往后放一个
			a[j+1] = a[j];
			j--;
		}

		// 放到该放的位置
		a[j+1]=tmp;
	}
}

// 插入排序，选中的牌冒泡向前插入
static void insert_sort_2(int a[], int n)
{
	int i=0;
	int j=0;
	//通过i选牌
	for (i=1; i < n; i++)
	{
		// 冒泡向前插入(i-1 --> 0)
		for (j=i-1; j>=0 && a[j] > a[j + 1]; j--)
		{
			swap(&a[j], &a[j+1]);
		}
	}
}


// 快速排序分区
static int partition(int a[], int p, int r)
{
	int x=0;
	int i=0;
	int j=0;
	// x为基准
	x = a[r];
	// i为界限,发现小于x的，就i++，再放到i处
	i = p-1;
	for (j=p; j<= r-1; j++)
	{
		if (a[j]<=x)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	// 至此，所有小于x的都到i左边了(a[0]~a[i-1])，a[r]是x，因此交换a[i+1]和a[r]
	swap(&a[i+1], &a[r]);
	return i+1;
}

// 快速排序
static void quick_sort(int a[], int p, int r)
{
	int q=0;
	if (p < r)
	{
		// 在数据集之中，选择一个元素作为"基准"（pivot）
		// 所有小于"基准"的元素，都移到"基准"的左边；所有大于"基准"的元素，都移到"基准"的右边
		q = partition(a, p, r);
		// 对"基准"左边和右边的两个子集，不断重复第一步和第二步，直到所有子集只剩下一个元素为止。
		quick_sort(a, p, q-1);
		quick_sort(a, q+1, r);
	}
}

// 希尔排序
static void shell_sort(int a[], int n)
{
	int i=0;
	int j=0;
	int tmp=0;
	int gap=0;
	while (gap <= n)
	{
		gap = gap*3 + 1;
	}
	while (gap > 0)
	{
		// 
		for (i = gap; i < n; i++)
		{
			// 冒泡向前插入(i-gap : gap : 0), 保证每列ok
			for (j = i - gap; (j >= 0) && (a[j] > a[j + gap]); j = j - gap)
			{
				swap(&a[j], &a[j+gap]);
			}
		}
		gap = (gap-1) / 3;
	}
}

void sort()
{
	int a1[]={3,24,2,1,99,2,34,22,32,11};
	int a2[]={3,24,2,1,99,2,34,22,32,11};
	int a3[]={3,24,2,1,99,2,34,22,32,11};
	int a4[]={3,24,2,1,99,2,34,22,32,11};
	int a5[]={3,24,2,1,99,2,34,22,32,11};
	printf("Origin Array:\n");
	print_a(a1, 10);

	// 冒泡排序
	printf("Bubble Sort:\n");
	bubble_sort(a1, 10);
	print_a(a1, 10);

	// 选择排序
	printf("Select Sort:\n");
	select_sort(a2, 10);
	print_a(a2, 10);

	// 快速排序
	printf("Quick Sort:\n");
	quick_sort(a3, 0, 9);
	print_a(a3, 10);

	// 插入排序
	printf("Insert Sort:\n");
	insert_sort_2(a4, 10);
	print_a(a4, 10);

	// 希尔排序
	printf("Shel Sort:\n");
	shell_sort(a5, 10);
	print_a(a5, 10);
}