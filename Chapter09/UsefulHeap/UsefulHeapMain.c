#include <stdio.h>
#include "UsefulHeap.h"

int DataPriorityCompare(char char1, char char2)
{
	return char2 - char1;
	// return char1 - char2;
}

int main(void)
{
	Heap heap;
	Init(&heap, DataPriorityCompare);

	Insert(&heap, 'A', 1);
	Insert(&heap, 'B', 2);
	Insert(&heap, 'C', 3);
	printf("%c \n", Delete(&heap));

	Insert(&heap, 'A', 1);
	Insert(&heap, 'B', 2);
	Insert(&heap, 'C', 3);
	printf("%c \n", Delete(&heap));

	while (!IsEmpty(&heap))
	{
		printf("%c \n", Delete(&heap));
	}

	return 0;
}