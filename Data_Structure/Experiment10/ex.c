#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* x, int* y)
{
	int* temp;
	temp = x;
	x = y;
	y = temp;
}

int partition(int* A, int p, int r)
{
	int x = A[r];
	int i = p - 1;
	int j;
	for(j = p; j < r; j++)
	{
		if(A[j] <= x)
		{
			i++;
			swap(A+i, A+j);
		}
	}
	swap(A+i+1, A+r);
	return i + 1;
}

void quicksort(int* A, int p, int r)
{
	if(p < r)
	{
		int q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q+1, r);
	}
}

void insertion_sort(int *A, int p, int len)
{
	if(len == 0)
	{
		*A = p;
	}
	else
	{
		int i = len - 1;
		while(i >= 0 && A[i] > p)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = p;
	}
}

int main()
{
	FILE *fp, *fpout;
	int len;
	//exercise1
	fp = fopen("/mnt/hgfs/GitHub/Data_Structure/Experiment10/p1in.txt	", "r");
	int *A;
	fscanf(fp, "%d", &len);
	A = (int*)malloc(len*sizeof(int));
	int len_now = 0, p;
	while(fscanf(fp, "%d", &p))
	{
		insertion_sort(A, p, len_now);
		len_now++;
	}
	fpout = fopen("mnt/hgfs/GitHub/Data_Structure/Experiment10/p1out.txt", "w");
	int i;
	for(i = 0; i < len; i++)
	{
		fprintf(fpout, "%d\n", A[i]);
	}

	//exercise2
	int len_2;
	FILE *fp2open, *fp2out;
	fp2open = fopen("/mnt/hgfs/GitHub/Data_Structure/Experiment10/p2in.txt	", "r");
	int *A2;
	int len2;
	fscanf(fp2open, "%d", &len2);
	A2 = (int*)malloc(len2*sizeof(int));
	int j;
	for(j = 0; j < len2; j++)
	{
		fscanf(fp2open, "%d", &A2[j]);
	}
	quicksort(A2, 0, len2);
	fp2out = fopen("/mnt/hgfs/GitHub/Data_Structure/Experiment10/p2out.txt", "w");
	for(j = 0; j < len; j++)
	{
		fprintf(fp2out, "%d\n", A[j]);
	}
	return 0;
}