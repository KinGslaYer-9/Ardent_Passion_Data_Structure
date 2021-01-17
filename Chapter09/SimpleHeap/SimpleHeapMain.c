#include <stdio.h>
#include "SimpleHeap.h"

int main(void)
{
	Heap heap;
	Init(&heap);					// 힙의 초기화

	Insert(&heap, 'A', 1);			// 문자 'A' 를 최고의 우선순위로 저장
	Insert(&heap, 'B', 2);			// 문자 'B' 를 두 번째 우선순위로 저장
	Insert(&heap, 'C', 3);			// 문자 'C' 를 세 번째 우선순위로 저장
	printf("%c \n", Delete(&heap));

	Insert(&heap, 'A', 1);			// 문자 'A' 를 한 번 더 저장
	Insert(&heap, 'B', 2);			// 문자 'B' 를 한 번 더 저장
	Insert(&heap, 'C', 3);			// 문자 'C' 를 한 번 더 저장
	printf("%c \n", Delete(&heap));

	while (!IsEmpty(&heap))
	{
		printf("%c \n", Delete(&heap));
	}

	return 0;
}