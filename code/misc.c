#include <stdio.h>
// �����������͵�ֵ
void swap(int *x, int *y)
{
	int tmp=0;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

//������ӡ����a��ǰn����
void print_a(int a[], int n)
{
	int i=0;
	for (i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}