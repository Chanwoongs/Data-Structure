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

bool checkParenthesis(const char* str)
{
	StackType s;
	char ch1;
	char ch2;

	initializeStack(&s);

	for (int i = 0; i < strlen(str); i++)
	{
		ch1 = str[i];

		switch (ch1)
		{
		case'(':
		case'{':
		case'[':
			push(&s, ch1);
			break;
		case')':
		case'}':
		case']':
			if (isEmpty(&s)) return false;
			ch2 = pop(&s);
			if ((ch1 == ')' && ch2 != '(') || (ch1 == '}' && ch2 != '{') || (ch1 == ']' && ch2 != '['))
			{
				return false;
				break;
			}
		}
	}
	if (!isEmpty(&s)) return false;

	return true;
}

int main()
{
	if (checkParenthesis("{(asfa)}"))
	{
		printf("True\n");
	}
	else printf("False\n");

	if (checkParenthesis("{)}"))
	{
		printf("True\n");
	}
	else printf("False\n");

	return 0;
}