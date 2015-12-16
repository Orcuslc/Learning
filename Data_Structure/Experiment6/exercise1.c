//experiment6.1

#include <stdio.h>

void exchange(int *a, int *b)
{
	int *temp = 0;
	temp = a;
	a = b;
	b = temp;
}

int partition(int *A, int p, int r)
{

	int x = A[r];
	int i = p - 1;
	int j;
	for(j = p; j <= r - 1; j++)
	{
		if(A[j] <= x)
		{
			i++;
			exchange(A+i, A+j);
		}
	}
	exchange(A+i+1, A+r);
	return i+1;
}

int quick_sort(int *A, int p, int r)
{
	int q;
	if(p < r)
	{
		q = partition(A, p, r);
		quick_sort(A, p, q-1);
		quick_sort(A, q+1, r);
	}
}

int sum_weight_huffmantree(int *A, int n)
{
	int i;
	int sum = 0;
	for(i = 1; i <= n - 1; i++)
	{
		quick_sort(A, 0, n - i);
		*(A+1) = *A + *(A+1);
		sum += *(A+1);
		A++;
	}
	sum += *(A+1);
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	int A[n];
	int i;
	for(i = 0; i < n; i++)
		scanf("%d", &A[i]);
	printf("%d\n", sum_weight_huffmantree(A, n));
	return 0;
}