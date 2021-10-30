#include<iostream>

int factorial(int n)
{
	if (n < 1) return 1;

	return n * factorial(n - 1);
}

int main()
{
	int n = 5;

	printf("%d factorial is %d\n", n, factorial(n));
}