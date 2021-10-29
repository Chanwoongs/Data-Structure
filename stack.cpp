#include<iostream>
#define SIZE 100

typedef int element;
typedef struct stackType
{
	element data[SIZE];
	int top;
}StackType;

void initializeStack(StackType *s)
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

int main()
{
	StackType *s;

	s = (StackType*)malloc(sizeof(StackType));

	initializeStack(s);

	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	pop(s);
	pop(s);
	pop(s);

	return 0;
}