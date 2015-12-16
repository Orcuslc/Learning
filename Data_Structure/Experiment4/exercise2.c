#include <stdio.h>

int main()
{
	FILE *fp = fopen("f:\\desktop\\test.txt", "r");
	char *s = fgetc(fp);
	char *t = "freedom";
	int x;
	x = calc_times(s, t);
	printf("%d\n", x);
	return 0;
}

int calc_times(char *s, char *t)
{
	int count = 0;
	while (*s != '\0')
	{
		int temp = 0;
		while(*t != 0)
		{
			if (*s == *t)
			{
				temp++;
				s++;
				t++;
			}
			else
				break;
		}
		if (*t == '\0')
		{
			count++;
			temp = 0;
		}
		s -= temp;
		t = 0;
	}
	return count;
}
