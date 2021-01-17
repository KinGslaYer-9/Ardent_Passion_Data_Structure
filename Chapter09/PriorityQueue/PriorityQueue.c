#include "PriorityQueue.h"

void QueueInit(PriorityQueue* priorityQueue, PriorityCompareFunction _compareFunction)
{
	Init(priorityQueue, _compareFunction);
}

int QueueIsEmpty(PriorityQueue* priorityQueue)
{
	IsEmpty(priorityQueue);
}

void PriorityEnqueue(PriorityQueue* priorityQueue, PriorityQueueData data)
{
	Insert(priorityQueue, data);
}

PriorityQueueData PriorityDequeue(PriorityQueue* priorityQueue)
{
	return Delete(priorityQueue);
}