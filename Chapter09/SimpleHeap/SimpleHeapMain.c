#include <stdio.h>
#include "SimpleHeap.h"

int main(void)
{
	Heap heap;
	Init(&heap);					// ���� �ʱ�ȭ

	Insert(&heap, 'A', 1);			// ���� 'A' �� �ְ��� �켱������ ����
	Insert(&heap, 'B', 2);			// ���� 'B' �� �� ��° �켱������ ����
	Insert(&heap, 'C', 3);			// ���� 'C' �� �� ��° �켱������ ����
	printf("%c \n", Delete(&heap));

	Insert(&heap, 'A', 1);			// ���� 'A' �� �� �� �� ����
	Insert(&heap, 'B', 2);			// ���� 'B' �� �� �� �� ����
	Insert(&heap, 'C', 3);			// ���� 'C' �� �� �� �� ����
	printf("%c \n", Delete(&heap));

	while (!IsEmpty(&heap))
	{
		printf("%c \n", Delete(&heap));
	}

	return 0;
}