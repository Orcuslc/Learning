#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

int *get_next_word(char *t)
{
	int k = -1, j = 0, *next;
	next = (int*)malloc(strlen(t) * sizeof(int));
	next[0] = -1;
	while(j < strlen(t) - 1)
	{
		if(k == -1 ||t[j] == t[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
	return next;
}

int match_word(char *s, char *t, int i)
{
	int j;
	if(strlen(s) - i < strlen(t))
		return -2;
	for(j = 0; j < strlen(t);)
	{
		if (t[j] == s[i+j])
			j++;
		else
			return j;
	}
	return -1;
}

int kmp(char *s, char *t)
{
	int *next;
	int i = 0, j, cond;
	next = get_next_word(t);
	while(1)
	{
		cond = match_word(s, t, i);
		if(cond == -1)
			return i;
		else if(cond == -2)
			break;
		else
			i += (cond - next[cond]);
	}
	return -1;
}

int main()
{
	char s[MAX], t[MAX];
	printf("Please input:\n");
	scanf("%s", s);
	scanf("%s", t);
	printf("Output:\n");
	printf("%d\n", kmp(s, t));
	return 0;
}
