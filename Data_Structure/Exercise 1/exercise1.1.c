#include <stdio.h>
#define MAX 999
int main()
{
	int count = 0, n, a[MAX], i;
	printf("Please Enter The Number:\n");
	scanf("%d", &n);
	printf("Please Enter The Scores:\n");
	while (count < n)
	{
		scanf("%d", &a[count]);
		count ++;
	}
	for (i = 0; i < count; i++)
	{
		if (a[i] >= 90)
		{
			printf("A\t");
		}
		else if (a[i] >= 80)
		{
			printf("B\t");
		}
		else if (a[i] >= 60)
		{
			printf("C\t");
		}
		else
		{
			printf("F\t");
		}
	}
}
