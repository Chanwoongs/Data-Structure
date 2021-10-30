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
	if ((q->rear + 1) % SIZE == q->front)
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
		q->rear = (q->rear + 1) % SIZE;
	
	printf("Enqueue %d\n", item);
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
	q->front = (q->front + 1) % SIZE;

	return temp;
}

void printQueue(QueueType* q)
{
	if (isEmpty(q))
	{
		printf("Queue is Empty\n");
		return;
	}
	if (q->front <= q->rear)
	{
		for (int i = q->front; i <= q->rear; i++)
		{
			printf("%d ", q->data[i]);
		}
	}
	else if (q->front > q->rear)
	{
		for (int i = q->front; i < SIZE; i++)
		{
			printf("%d ", q->data[i]);
		}
		for (int i = 0; i <= q->rear; i++)
		{
			printf("%d ", q->data[i]);
		}
	}
	printf("\n");
	printf("front = %d, rear = %d\n", q->front, q->rear);
	printf("\n");
}

int main()
{
	QueueType queue;
	int x;

	initializeQueue(&queue);

	enqueue(&queue, 10);
	printQueue(&queue);

	enqueue(&queue, 20);
	printQueue(&queue);

	enqueue(&queue, 30);
	printQueue(&queue);

	enqueue(&queue, 40);
	printQueue(&queue);

	enqueue(&queue, 50);
	printQueue(&queue);

	x = dequeue(&queue);
	printf("Dequeued item: %d \n", x);
	printQueue(&queue);

	x = dequeue(&queue);
	printf("Dequeued item: %d \n", x);
	printQueue(&queue);

	x = dequeue(&queue);
	printf("Dequeued item: %d \n", x);
	printQueue(&queue);

	enqueue(&queue, 10);
	printQueue(&queue);

	enqueue(&queue, 20);
	printQueue(&queue);

	enqueue(&queue, 30);
	printQueue(&queue);

	x = dequeue(&queue);
	printf("Dequeued item: %d \n", x);
	printQueue(&queue);

	return 0;
}