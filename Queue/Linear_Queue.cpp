#include<iostream>
#define SIZE 5

typedef int element;
typedef struct {
	element  data[SIZE];
	int  front, rear;
} QueueType;

void initializeQueue(QueueType* q)
{
	q->front = -1;
	q->rear = -1;
}

bool isFull(QueueType* q) 
{
	if (q->rear == SIZE - 1)
	{
		return true;
	}
	else return false;
}

bool isEmpty(QueueType* q)
{
	if (q->front == -1 && q->rear == -1)
	{
		return true;
	}
	else return false;
}

void enqueue(QueueType* q, element item)
{
	if (isFull(q))
	{
		printf("Queue is Full!\n");
		return;
	}

	if (isEmpty(q))
	{
		q->front += 1;
		q->rear += 1;
	}
	else
		q->rear += 1;

	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	element temp;

	if (isEmpty(q))
	{
		printf("Queue is Empty\n");
		exit(0);
	}

	temp = q->data[q->front];

	if (q->front == q->rear)
	{
		q->front = -1;
		q->rear = -1;
	}
	else q->front += 1;

	return temp;
}

void printQueue(QueueType* q)
{
	if (isEmpty(q))
	{
		printf("Queue is Empty\n");
		return;
	}
	for (int i = q->front; i <= q->rear; i++)
	{
		printf("%d ", q->data[i]);
	}
	printf("\n");
}

int main()
{
	element item = 0;
	QueueType q;

	initializeQueue(&q);

	enqueue(&q, 10); 
	printQueue(&q);
	enqueue(&q, 20); 
	printQueue(&q);
	enqueue(&q, 30); 
	printQueue(&q);

	item = dequeue(&q); 
	printQueue(&q);
	item = dequeue(&q); 
	printQueue(&q);
	item = dequeue(&q); 
	printQueue(&q);

	return 0;
}