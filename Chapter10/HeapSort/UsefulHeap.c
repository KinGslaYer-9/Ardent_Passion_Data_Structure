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

// �� ���� �ڽ� ��� �� ���� �켱������ �ڽ� ��� �ε��� �� ��ȯ
int GetHighPriorityChildIndex(Heap* heap, int index)
{
	// �ڽ� ��尡 �������� �ʴ´ٸ�,
	if (GetLeftChildIndex(index) > heap->numberOfData)
	{
		return 0;
	}
	// �ڽ� ��尡 ���� �ڽ� ��� �ϳ��� �����Ѵٸ�,
	else if (GetLeftChildIndex(index) == heap->numberOfData)
	{
		return GetLeftChildIndex(index);
	}
	// �ڽ� ��尡 �� �� �����Ѵٸ�,
	else
	{
		// ������ �ڽ� ����� �켱������ ���ٸ�,
		if (heap->compareFunction(heap->heapArray[GetLeftChildIndex(index)], heap->heapArray[GetRightChildIndex(index)]) < 0)
		{
			return GetRightChildIndex(index);
		}
		// ���� �ڽ� ����� �켱������ ���ٸ�,
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