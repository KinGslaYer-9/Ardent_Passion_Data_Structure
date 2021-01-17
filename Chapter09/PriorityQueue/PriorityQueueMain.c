#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityCompare(char char1, char char2)
{
	return char2 - char1;
}

int main(void)
{
	PriorityQueue priorityQueue;
	QueueInit(&priorityQueue, DataPriorityCompare);

	PriorityEnqueue(&priorityQueue, 'A', 1);
	PriorityEnqueue(&priorityQueue, 'B', 2);
	PriorityEnqueue(&priorityQueue, 'C', 3);
	printf("%c \n", PriorityDequeue(&priorityQueue));

	PriorityEnqueue(&priorityQueue, 'A', 1);
	PriorityEnqueue(&priorityQueue, 'B', 2);
	PriorityEnqueue(&priorityQueue, 'C', 3);
	printf("%c \n", PriorityDequeue(&priorityQueue));

	while (!QueueIsEmpty(&priorityQueue))
	{
		printf("%c \n", PriorityDequeue(&priorityQueue));
	}

	return 0;
}