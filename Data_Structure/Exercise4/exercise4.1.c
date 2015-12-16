#include <string.h>
#include <stdio.h>
void Del(char *s, char ch) 
{
	int len = strlen(s);
	int count = 0, i = 0;
	char *temp;
	while (*(s+i) != '\0')
	{
		if (*(s+i) != ch)
		{
			*(temp+count) = *(s+i);
			count++;
		}
		i++;
	}
	*s = *temp;
}

int main()
{
	;
}
