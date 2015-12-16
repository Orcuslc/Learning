//Exercise 1
void test(int sum)
{
	int x;
	scanf(x);
	while(x != 0)
	{
		sum += x;
		print(sum);
		scanf(x);
	}
	print(sum);
}