#include <stdio.h>
#define MAX 999

int is_valid(int A[])
{
	int flag, i;
	for (i = 0; i <= MAX; i++)
	{
		if (A[i] != 0)
		{
			flag = A[i];	
			break;
		}
	}
	for (i = 0; i <= MAX; i++)
	{
		if (A[i] != flag && A[i] != 0)
			return 1;
	}
	return -1;
}

void get_mode(int A[])
{
	int flag = A[0], index = 0, key = 0, i, valid;
	int result[MAX];
	valid = is_valid(A);
	if (valid == -1)
	{
		printf("invalid\n");
	}
	else
	{
		int prev_count = 0, now_count = 0;
		for (i = 0; i < MAX; i++)
		{
			if (A[i] > flag)
			{
				flag = A[i];
				index = i;
			}
		}	
		printf("%d\t", index);
		prev_count = flag;
		A[index] = 0;
		flag = 0;
		index = 0;
		for (i = 0; i < MAX; i++)
		{
			if (A[i] > flag)
			{
				flag = A[i];
				index = i;
			}
		}
		now_count = flag;
		while(now_count == prev_count)
		{
			printf("%d\t", index);
			A[index] = 0;
			flag = 0;
			index = 0;
			for (i = 0; i < MAX; i++)
			{
				if (A[i] > flag)
				{
					flag = A[i];
					index = i;
				}
			}
			prev_count = now_count;
			now_count = flag;
		}
		printf("\n");	
	}
}	


float get_average(int A[], int n)
{
	int sum = 0,i;
	for (i = 0; i < n; i++)
		sum += A[i];
	return sum/(float)n;
}
		
float get_mid(int A[], int n)
{
	if (n%2 != 0)
	{
		int mid = (n + 1)/2;
		int count = 0, i;
		for(i = 0; i < MAX; i++)
		{
			if (count < mid && count + A[i] >= mid)
				return i;
			count += A[i];
		}
	}
	else
	{	
		int mid1 = n/2;
		int mid2 = n/2 + 1;
		int count = 0,i,j;
		for (i = 0, j = 0; i < MAX; i++)
		{
			if (count < mid1 && count + A[i] >= mid2)
				return i;	
			else if (count == mid1)
				{
					j = i - 1;
					int k;
					for(k = i; k < MAX; k++)
						{
							if (A[k] != 0)
								return (float)(k + j)/(float)2;
						}
				}
			count += A[i];
		}
	}
}
				
int main()
{
	int i, n, a[MAX], b[MAX], value[MAX], mode, count = 0;
	float average, mid;
	printf("Please Enter the Number:\n");
	scanf("%d", &n);
	printf("Please Enter the Numbers:\n");
	while (count < n)
	{
		scanf("%d", &a[count]);
		count++;
	}
	for (i = 0; i < MAX; i ++)
	{
		b[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		b[a[i]]++;
	}
	average = get_average(a, n);
	mid = get_mid(b, n);
	get_mode(b);
	printf("%f\n", average);
	printf("%f\n", mid);	
	return 0;
}
