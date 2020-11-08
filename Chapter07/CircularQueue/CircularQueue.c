#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == pq->rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void Enqueue(Queue* pq, Data data)
{
	if (NextIndex(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextIndex(pq->rear);
	pq->queueArray[pq->rear] = data;
}

Data Dequeue(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextIndex(pq->front);

	return pq->queueArray[pq->front];
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queueArray[NextIndex(pq->front)];
}

int NextIndex(int currentIndex)
{
	if (currentIndex == QUEUE_LENGTH - 1)
	{
		return 0;
	}
	else
	{
		return currentIndex + 1;
	}
}