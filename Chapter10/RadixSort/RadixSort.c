#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_SIZE			10

void RadixSort(int arr[], int size, int maxLength)
{
	// 매개변수 maxLength 에는 정렬대상 중 가장 긴 데이터의 길이 정보가 전달
	Queue buckets[BUCKET_SIZE];

	int divfac = 1;
	int radix;
	
	// bi == bucketIndex
	// pos == position, di == digitIndex
	for (int bi = 0; bi < BUCKET_SIZE; bi++)
	{
		QueueInit(&buckets[bi]);
	}

	// 가장 긴 데이터의 길이만큼 반복
	for (int pos = 0; pos < maxLength; pos++)
	{
		// 정렬대상의 수만큼 반복
		for (int di = 0; di < size; di++)
		{
			// N번째 자리의 숫자 추출
			radix = (arr[di] / divfac) % 10;

			// 추출한 숫자를 근거로 버킷에 데이터 저장
			Enqueue(&buckets[radix], arr[di]);
		}

		// 버킷 수만큼 반복
		for (int bi = 0, di = 0; bi < BUCKET_SIZE; bi++)
		{
			// 버킷에 저장된 것 순서대로 다 꺼내서 다시 arr에 저장
			while (!QIsEmpty(&buckets[bi]))
			{
				arr[di++] = Dequeue(&buckets[bi]);
			}
		}

		// N번째 자리의 숫자 추출을 위한 피제수의 증가
		divfac *= 10;
	}
}

int main(void)
{
	int arr[7] = { 13, 212, 14, 7141, 10987, 6, 15 };

	int len = sizeof(arr) / sizeof(int);

	RadixSort(arr, len, 5);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	puts("\n");
	return 0;
}