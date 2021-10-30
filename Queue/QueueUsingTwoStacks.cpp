#include<iostream>

#define SIZE 5
typedef int element;

typedef struct {
	element data[SIZE];
	int top;
} StackType;

typedef struct {
	StackType* s1;
	StackType* s2;
} QueueUsingTwoStacks;

void initializeQueue(QueueUsingTwoStacks* q)
{
	q->s1 = new StackType;
	q->s2 = new StackType;
	q->s1->top = -1;
	q->s2->top = -1;
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
	if (isFull(s))
	{
		printf("Queue is Full\n");
		return;
	}

	s->top++;

	s->data[s->top] = item;
}

element pop(StackType* s)
{
	if (isEmpty(s))
	{
		printf("Queue is Empty\n");
		exit(0);
	}
	element temp;
	temp = s->data[s->top];
	s->top--;

	return temp;
}

void enqueue(QueueUsingTwoStacks* q, element item)
{
	push(q->s1, item);
}

element dequeue(QueueUsingTwoStacks* q)
{
	element temp;

	for (int i = 0; i <= q->s1->top; i++)
	{
		q->s2->data[i] = pop(q->s1);
	}

	temp = pop(q->s2);

	return temp;
}

int main()
{
	QueueUsingTwoStacks q;

	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);

	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
}