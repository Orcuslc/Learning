#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int get_length(char *s)
{
	char *t = s;
	int count = 0;
	while (*t != '\0')
	{
		count++;
		t++;
	}
	return count;
}

void copy_string(char *t, char *s)
{
	while(*s != '\0')
	{
		*t = *s;
		t++;
		s++;
	}
	*t = '\0';	
}

int compare_string(char *s, char *t)
{
	while(*s != '\0')
	{
		if (*s == *t)
		{
			s++;
			t++;
		}
		else
			return -1;
	}
	if (*t == '\0')
		return 1;
}

char* join_string(char *s, char *t)
{
	char *x[MAX];
	int i = 0;
	while(*s != '\0')
	{
		*x[i] = *s;
		i++;
		s++;
	}
	while(*t != '\0')
	{
		*x[i] = *t;
		i++;
		t++;
	}
	*x[i] = '\0';
	return *x;
}

int main()
{
	char *a;
	a = "123445";
	int b;
	b = get_length(a);
	printf("%d\n", b);
	char *c[MAX];
	copy_string(c, a);
	printf("%s\n", c);
	int x;
	char *d = "123";
	x = compare_string(a, d);
	printf("%d\n", x);
	char *y;
	char *e = "12335";
	char *f = "97786";
	y = join_string(e, f);
	printf("%s\n", y);
	return 0;
}
