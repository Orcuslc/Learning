/* exercise 1.c
	15.10.19*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int matrix_multiple(int m, int n, int p, int *A, int *B, int i, int j)
{
	//evaluate the inner_multiple of Line i of A and column j of B
	int sum = 0;
	int k = 0;
	for(k = 0; k < n; k++)
	{
		sum += (*(A + n*i + k) * (*(B + p*k + j)));
	}
	return sum;
}

int main()
{
	int i, j, m, n, p;
	scanf("%d", &m);
	scanf("%d", &n);
	scanf("%d", &p);
	int *A, *B, *C;
	A = (int*)malloc(sizeof(int) * m * n);
	B = (int*)malloc(sizeof(int) * n * p);
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{

			scanf("%d", A + n * i + j);
		}
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < p; j++)
		{
			scanf("%d", B + p * i + j);
		}
	}
	C = (int*)malloc(m * p * sizeof(int));
	printf("The Result Is:\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < p; j++)
		{
			*(C + p * i + j) = matrix_multiple(m,n,p,A,B,i,j);
			printf("%d\t", *(C + p*i +j));
		}
		printf("\n");
	}
	return 0;
}

