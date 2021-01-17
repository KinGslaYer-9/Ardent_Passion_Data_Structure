#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "UsefulHeap.h"

typedef Heap PriorityQueue;
typedef Data PriorityQueueData;

void QueueInit(PriorityQueue* priorityQueue, PriorityCompareFunction _compareFunction);
int QueueIsEmpty(PriorityQueue* priorityQueue);

void PriorityEnqueue(PriorityQueue* priorityQueue, PriorityQueueData data);
PriorityQueueData PriorityDequeue(PriorityQueue* priorityQueue);

#endif // !__PRIORITY_QUEUE_H__
