#include "SimpleHeap.h"

void Init(Heap* heap)
{
	heap->numberOfData = 0;
}

int IsEmpty(Heap* heap)
{
	if (heap->numberOfData == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int GetParentIndex(int index)
{
	return index / 2;
}

int GetLeftChildIndex(int index)
{
	return index * 2;
}

int GetRightChildIndex(int index)
{
	return GetLeftChildIndex(index) + 1;
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
int GetHighPriorityChildIndex(Heap* heap, int index)
{
	// 자식 노드가 존재하지 않는다면,
	if (GetLeftChildIndex(index) > heap->numberOfData)
	{
		return 0;
	}
	// 자식 노드가 왼쪽 자식 노드 하나만 존재한다면,
	else if (GetLeftChildIndex(index) == heap->numberOfData)
	{
		return GetLeftChildIndex(index);
	}
	// 자식 노드가 둘 다 존재한다면,
	else
	{
		// 오른쪽 자식 노드의 우선순위가 높다면,
		if (heap->heapArray[GetLeftChildIndex(index)].priority > heap->heapArray[GetRightChildIndex(index)].priority)
		{
			return GetRightChildIndex(index);
		}
		// 왼쪽 자식 노드의 우선순위가 높다면,
		else
		{
			return GetLeftChildIndex(index);
		}
	}
}

void Insert(Heap* heap, Data data, Priority priority)
{
	int index = heap->numberOfData + 1;
	HeapElement newElement = { priority, data };

	while (index != 1)
	{
		if (priority < (heap->heapArray[GetParentIndex(index)].priority))
		{
			heap->heapArray[index] = heap->heapArray[GetParentIndex(index)];
			index = GetParentIndex(index);
		}
		else
		{
			break;
		}
	}

	heap->heapArray[index] = newElement;
	heap->numberOfData += 1;
}

Data Delete(Heap* heap)
{
	Data returnData = (heap->heapArray[1]).data;
	HeapElement lastElement = heap->heapArray[heap->numberOfData];

	int parentIndex = 1;
	int childIndex;

	while (childIndex = GetHighPriorityChildIndex(heap, parentIndex))
	{
		if (lastElement.priority <= heap->heapArray[childIndex].priority)
		{
			break;
		}

		heap->heapArray[parentIndex] = heap->heapArray[childIndex];
		parentIndex = childIndex;
	}

	heap->heapArray[parentIndex] = lastElement;
	heap->numberOfData -= 1;

	return returnData;
}