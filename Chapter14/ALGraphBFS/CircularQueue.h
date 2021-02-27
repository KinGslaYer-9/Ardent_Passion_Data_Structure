#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define TRUE			1
#define FALSE			0

#define QUEUE_LENGTH	100
typedef int Data;

typedef struct _circularQueue
{
	int front;
	int rear;
	Data queueArray[QUEUE_LENGTH];
} CircularQueue;

typedef CircularQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif // !__C_QUEUE_H__
