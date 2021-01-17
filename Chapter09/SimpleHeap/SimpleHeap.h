#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE			1
#define FALSE			0

#define HEAP_LENGTH		100

typedef char Data;
typedef int Priority;

typedef struct _heapElement
{
	Priority priority;		// 값이 작을수록 높은 순위
	Data data;
} HeapElement;

typedef struct _heap
{
	int numberOfData;
	HeapElement heapArray[HEAP_LENGTH];
} Heap;

void Init(Heap* heap);
int IsEmpty(Heap* heap);

void Insert(Heap* heap, Data data, Priority priority);
Data Delete(Heap* heap);

#endif // !__SIMPLE_HEAP_H__
