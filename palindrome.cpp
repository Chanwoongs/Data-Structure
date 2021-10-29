#include<iostream>
#define SIZE 100

typedef char element;
typedef struct stackType
{
	element data[SIZE];
	int top;
}StackType;

void initializeStack(StackType* s)
{
	s->top = -1;
}

bool isFull(StackType* s)
{
	if (s->top == SIZE - 1) return true;

	else return false;
}

bool isEmpty(StackType* s)
{
	if (s->top == -1) return true;

	else return false;
}

void push(StackType* s, element item)
{
	if (isFull(s)) return;

	s->top++;
	s->data[s->top] = item;
}

element pop(StackType* s)
{
	if (isEmpty(s)) exit(0);

	element temp;
	temp = s->data[s->top];
	s->top--;

	return temp;
}

element peek(StackType* s)
{
	if (isEmpty(s)) exit(0);

	return s->data[s->top];
}

bool checkPalindrome(const char* str)
{
	StackType s;
	char c = '\0';

	initializeStack(&s);

	for (int i = 0; i < strlen(str); i++)
	{
		c = tolower(str[i]);
		if (c < 97 || c >121) continue;
		push(&s, c);
	}
	for (int i = 0; i < s.top + 1; i++)
	{
		if (pop(&s) != s.data[i])
		{
			return false;
			break;
		}
	}
	return true;
}

int main()
{
	const char* str1 = "madam, I’m Adam";

	printf("%s\n", str1);

	if (checkPalindrome(str1)) {
		printf("Palindrome!\n");
	}
	else printf("Not Palindrome\n");

	const char* str2 = "Ey....................E";

	printf("%s\n", str2);

	if (checkPalindrome(str2)) {
		printf("Palindrome!\n");
	}
	else printf("Not Palindrome\n");

	const char* str3 = "r!@%$#%ac!@#@!e#C^a&^r";

	printf("%s\n", str3);

	if (checkPalindrome(str3)) {
		printf("Palindrome!\n");
	}
	else printf("Not Palindrome\n");

	const char* str4 = "awwa";

	printf("%s\n", str4);

	if (checkPalindrome(str4)) {
		printf("Palindrome!\n");
	}
	else printf("Not Palindrome\n");

	return 0;
}