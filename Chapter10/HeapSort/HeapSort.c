#include <stdio.h>
#include "UsefulHeap.h"

int PriorityCompare(int number1, int number2)
{
	return number2 - number1;
	// return number1 - number2;
}

void HeapSort(int arr[], int size, PriorityCompareFunction priorityCompare)
{
	Heap heap;

	Init(&heap, priorityCompare);

	// ���Ĵ���� ������ ���� �����Ѵ�.
	for (int i = 0; i < size; i++)
	{
		Insert(&heap, arr[i]);
	}

	// ������� �ϳ��� ������ ������ �ϼ��Ѵ�.
	for (int i = 0; i < size; i++)
	{
		arr[i] = Delete(&heap);
	}
}

int main(void)
{
	int arr[4] = { 3, 4, 2, 1 };
	
	HeapSort(arr, sizeof(arr) / sizeof(int), PriorityCompare);

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arr[i]);
	}

	puts("\n");
	return 0;
}