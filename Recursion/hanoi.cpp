#include<iostream>

void hanoi(int n, char start, char temp, char goal)
{
	if (n == 1)
		printf("Move disc %d from %c to %c\n", n, start, goal);
	else
	{
		hanoi(n - 1, start, goal, temp);
		printf("Move disc %d from %c to %c\n", n, start, goal);
		hanoi(n - 1, temp, start, goal);
	}
}

int main()
{
	int n = 3;
	hanoi(n, 'A', 'B', 'C');

	return 0;
}