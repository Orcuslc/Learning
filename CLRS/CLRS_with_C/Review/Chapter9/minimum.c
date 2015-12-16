/*review of chapter 9*/
/*15.8.9*/
#include <stdio.h>

int minimum(int *pa, int n)
{
	int flag = *pa;
	int i;
	for(i = 1; i < n; i++)
	{
		flag = (flag > *(pa+i)) ? *(pa+i) : flag;
	}
	return flag;
}
void main()
{
	int A[] = {1,2,3,4,5,6};
	int n = 6;
	int *pa = &A[0];
	printf("%d\n", minimum(pa, n));
}