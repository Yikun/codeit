#include <stdio.h>

#include "misc.h"

// ð������
static void bubble_sort(int a[], int n)
{
	int i = 0;
	int j = 0;
	for (i=0; i<n-1; i++)
	{
		// �Ƚ�����Ԫ�أ���a[j]��a[j+1]���򽻻�
		// a[j]����һ������һ��������������λ����
		for(j=0; j<n-1-i; j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j], &a[j+1]);
			}
		}
	}
}

// ѡ������
static void select_sort(int a[], int n)
{
	int i=0,j=0,min=0;
	for (i=0; i < n-1; i++)
	{
		min = i;
		// �ҵ���Сֵ
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

// ��������, ������������
static void insert_sort(int a[], int n)
{
	int i=0;
	int j=0;
	int tmp=0;
	for (i = 1; i < n; i++)
	{
		// ȡ��
		tmp = a[i];
		// ��ǰ�����ʼλ��
		j = i - 1;

		// ���a[j]���ź��棬Ѱ�ҳ�j
		while ((j >= 0) && a[j] > tmp)
		{
			// �����һ��
			a[j+1] = a[j];
			j--;
		}

		// �ŵ��÷ŵ�λ��
		a[j+1]=tmp;
	}
}

// ��������ѡ�е���ð����ǰ����
static void insert_sort_2(int a[], int n)
{
	int i=0;
	int j=0;
	//ͨ��iѡ��
	for (i=1; i < n; i++)
	{
		// ð����ǰ����(i-1 --> 0)
		for (j=i-1; j>=0 && a[j] > a[j + 1]; j--)
		{
			swap(&a[j], &a[j+1]);
		}
	}
}


// �����������
static int partition(int a[], int p, int r)
{
	int x=0;
	int i=0;
	int j=0;
	// xΪ��׼
	x = a[r];
	// iΪ����,����С��x�ģ���i++���ٷŵ�i��
	i = p-1;
	for (j=p; j<= r-1; j++)
	{
		if (a[j]<=x)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	// ���ˣ�����С��x�Ķ���i�����(a[0]~a[i-1])��a[r]��x����˽���a[i+1]��a[r]
	swap(&a[i+1], &a[r]);
	return i+1;
}

// ��������
static void quick_sort(int a[], int p, int r)
{
	int q=0;
	if (p < r)
	{
		// �����ݼ�֮�У�ѡ��һ��Ԫ����Ϊ"��׼"��pivot��
		// ����С��"��׼"��Ԫ�أ����Ƶ�"��׼"����ߣ����д���"��׼"��Ԫ�أ����Ƶ�"��׼"���ұ�
		q = partition(a, p, r);
		// ��"��׼"��ߺ��ұߵ������Ӽ��������ظ���һ���͵ڶ�����ֱ�������Ӽ�ֻʣ��һ��Ԫ��Ϊֹ��
		quick_sort(a, p, q-1);
		quick_sort(a, q+1, r);
	}
}

// ϣ������
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
			// ð����ǰ����(i-gap : gap : 0), ��֤ÿ��ok
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

	// ð������
	printf("Bubble Sort:\n");
	bubble_sort(a1, 10);
	print_a(a1, 10);

	// ѡ������
	printf("Select Sort:\n");
	select_sort(a2, 10);
	print_a(a2, 10);

	// ��������
	printf("Quick Sort:\n");
	quick_sort(a3, 0, 9);
	print_a(a3, 10);

	// ��������
	printf("Insert Sort:\n");
	insert_sort_2(a4, 10);
	print_a(a4, 10);

	// ϣ������
	printf("Shel Sort:\n");
	shell_sort(a5, 10);
	print_a(a5, 10);
}