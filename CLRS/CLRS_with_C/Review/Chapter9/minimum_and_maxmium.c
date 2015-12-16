/*review of chapter 9*/
/*15.8.9*/
#include <stdio.h>

int minimum_and_maxmium(int *pa, int n)
{
	int i, flag1, flag2, small, big;
	if(n % 2 == 0)
	{
		flag1 = (*pa < *(pa+1)) ? *pa : *(pa+1);
		flag2 = (*pa < *(pa+1)) ? *(pa+1) : *pa;	
		i = 2;
	}
	else
	{
		flag1 = *pa;
		flag2 = *pa;
		i = 1;
	}
	while (i < n)
		{
			small = (*(pa+i) < *(pa+i+1)) ? *(pa+i) : *(pa+i+1);
			big = (*(pa+i) < *(pa+i+1)) ? *(pa+i+1) : *(pa+i);
			flag1 = (small < flag1) ? small : flag1;
			flag2 = (big > flag2) ? big : flag2;
			i = i + 2;
		}
	return(flag1, flag2);
}

int main()
{
	int A[] = {1,2,3,4,5};
	int *pa = &A[0];
	int n = 5;
	int min1, max1;
	min1, max1 = minimum_and_maxmium(pa, n);
	printf("%d\t%d\n", min1, max1);
}