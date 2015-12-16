#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000

int* get_next(char* s)
{
	int *next;
	next = (int*)malloc(strlen(s) * sizeof(int));
	next[0] = -1;
	int i = 0, j = -1;
	while(i < strlen(s) - 1)
	{
		if(j == -1 || *(s + i) == *(s + j))
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
	return next;
}

int index_kmp(char* s, char* t, int pos)
{
	int i = pos;
	int j = 0;
	int *next;
	next = get_next(t);
	printf("%d\n", strlen(t));
	while(i < strlen(s) && j < strlen(t))
	{
		if(j == 0 || *(s + i) == *(t + j))
		{
			i++;
			j++;
		}
		else
			j = *(next + j);
		printf("%d\t", i);
		printf("%d\n", j);
	}
	printf("%d\n", i);
	if(j > strlen(t))
		return i - strlen(t);
	else
		return -100;
}

int main()
{
	char *s, *t;
	int result, pos = 0;
	scanf("%s", s);
	scanf("%s", t);
	result = index_kmp(s, t, pos);
	printf("%d\n", result);
}