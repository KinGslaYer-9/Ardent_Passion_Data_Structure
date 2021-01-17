#include "UsefulHeap.h"

void Init(Heap* heap, PriorityCompareFunction _compareFunction)
{
	heap->numberOfData = 0;
	heap->compareFunction = _compareFunction;
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
		if (heap->compareFunction(heap->heapArray[GetLeftChildIndex(index)], heap->heapArray[GetRightChildIndex(index)]) < 0)
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

void Insert(Heap* heap, Data data)
{
	int index = heap->numberOfData + 1;

	while (index != 1)
	{
		if (heap->compareFunction(data, heap->heapArray[GetParentIndex(index)]) > 0)
		{
			heap->heapArray[index] = heap->heapArray[GetParentIndex(index)];
			index = GetParentIndex(index);
		}
		else
		{
			break;
		}
	}

	heap->heapArray[index] = data;
	heap->numberOfData += 1;
}

Data Delete(Heap* heap)
{
	Data returnData = heap->heapArray[1];
	Data lastElement = heap->heapArray[heap->numberOfData];

	int parentIndex = 1;
	int childIndex;

	while (childIndex = GetHighPriorityChildIndex(heap, parentIndex))
	{
		if (heap->compareFunction(lastElement, heap->heapArray[childIndex]) >= 0)
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