//exercise 3.1
//main.c
#include <stdio.h>
#include "Stack.h"
#include "Stack.c"
#define MAX 999

int match(char *data, int n)
{
	Stack *s;
	Elemtype *e;
	int i;
	
	for(i = 0; i < n; i++)
	{
		if (data[i] == '(' || data[i] == '{' || data[i] == '[')
			push(s, data[i]);
		else if (data[i] == ')')
		{
			get_top(s, e);
			{
				if (*e == '(')
					pop(s, e);
				else
					push(s, data[i]);
			}
		}	
		else if (data[i] == '}')
		{
			get_top(s, e);
			{
				if (*e == '{')
					pop(s, e);
				else
					push(s, data[i]);
			}
		}		
		else if (data[i] == ']')
		{
			get_top(s, e);
			{
				if (*e == '[')
					pop(s, e);
				else
					push(s, data[i]);
			}
		}
		else
			push(s, data[i]);
	}
	if (is_empty(s))
		return 1;
	else
		return -1;
}

int main()
{
	int a;
	char data[MAX];
	char c;
	int count = 0,i;
	while(getchar() != EOF)
	{
		scanf("%s", &data[count]);
		count++;
	}
	a = match(data, count);
	if (a == 1)
	{
		printf("MATCH\n");
		return 0;
	}
	else
	{
		printf("MISMATCH\n");
		return 0;
	}
}	
