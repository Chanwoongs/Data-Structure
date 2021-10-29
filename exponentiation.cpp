#include <iostream>

int power(int num, int ex)
{
	if (ex == 0) return 1;

	if (ex % 2 == 0)
	{
		return power(num * num, num / 2);
	}

	else return num * power(num * num, (num - 1) / 2);
}

int main()
{
	int num = 2;
	int ex = 10;

	printf("%d^%d = %d\n", num, ex, power(num, ex));

	return 0;
}