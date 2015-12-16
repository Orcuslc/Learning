#include <stdio.h>

int minimum_and_maximum(int *A[], int n)
{
	int max, min, i, j, big, small;
	if(A[0] < A[1])
	{
		min = A[0];
		max = A[1];
	}
	else
	{
		min = A[1];
		max = A[0];
	}
	for (i = 0; i <= n - 1; i++)
	{
		for (j = i+1; j <= n - 1; j++)
		{
			if (A[i] < A[j])
			{
				if (A[i] < min)
					min = A[i];
				if (A[j] > max)
					max = A[j];
			}
			else
			{
				if (A[i] > max)
					max = A[i];
				if (A[j] < min)
					min = A[j];
			}
		}
	}
	return min, max;
}

int main()
{
	int *A = (9,8,7,6,5,4,3,2,1);
	int n = 9;
	int min, max;
	min, max = minimum_and_maximum(*A, n);
	printf("%d\n%d\n", min, max);
	return 0;
}
