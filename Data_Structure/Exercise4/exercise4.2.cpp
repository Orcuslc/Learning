char firstSingle(char *str)
{
	int ascii[255] = {0};
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		ascii[str[i]]++;
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (ascii[str[i]] == 1)
			return str[i];
	}
	return '\0';
}

int main()
{
	return 0;
}
