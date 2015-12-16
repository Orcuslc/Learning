#include <stdio.h>

int minimum_and_maximum(int A[], int n)
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