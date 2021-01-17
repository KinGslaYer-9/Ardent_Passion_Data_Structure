#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityCompare(char* string1, char* string2)
{
	return string2 - string1;
}

int main(void)
{
	PriorityQueue priorityQueue;
	QueueInit(&priorityQueue, DataPriorityCompare);

	PriorityEnqueue(&priorityQueue, "Hello World!");
	PriorityEnqueue(&priorityQueue, "Good Morning");
	PriorityEnqueue(&priorityQueue, "C Programming");
	PriorityEnqueue(&priorityQueue, "C++ Programming");

	while (!QueueIsEmpty(&priorityQueue))
	{
		printf("%s \n", PriorityDequeue(&priorityQueue));
	}

	return 0;
}