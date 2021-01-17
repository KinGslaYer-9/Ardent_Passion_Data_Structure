#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE			1
#define FALSE			0

#define HEAP_LENGTH		100

typedef char Data;
typedef int PriorityCompareFunction(Data data1, Data data2);

typedef struct _heap
{
	PriorityCompareFunction* compareFunction;
	int numberOfData;
	Data heapArray[HEAP_LENGTH];
} Heap;

void Init(Heap* heap, PriorityCompareFunction _compareFunction);
int IsEmpty(Heap* heap);

void Insert(Heap* heap, Data data);
Data Delete(Heap* heap);

#endif // !__USEFUL_HEAP_H__
