#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_SIZE			10

void RadixSort(int arr[], int size, int maxLength)
{
	// �Ű����� maxLength ���� ���Ĵ�� �� ���� �� �������� ���� ������ ����
	Queue buckets[BUCKET_SIZE];

	int divfac = 1;
	int radix;
	
	// bi == bucketIndex
	// pos == position, di == digitIndex
	for (int bi = 0; bi < BUCKET_SIZE; bi++)
	{
		QueueInit(&buckets[bi]);
	}

	// ���� �� �������� ���̸�ŭ �ݺ�
	for (int pos = 0; pos < maxLength; pos++)
	{
		// ���Ĵ���� ����ŭ �ݺ�
		for (int di = 0; di < size; di++)
		{
			// N��° �ڸ��� ���� ����
			radix = (arr[di] / divfac) % 10;

			// ������ ���ڸ� �ٰŷ� ��Ŷ�� ������ ����
			Enqueue(&buckets[radix], arr[di]);
		}

		// ��Ŷ ����ŭ �ݺ�
		for (int bi = 0, di = 0; bi < BUCKET_SIZE; bi++)
		{
			// ��Ŷ�� ����� �� ������� �� ������ �ٽ� arr�� ����
			while (!QIsEmpty(&buckets[bi]))
			{
				arr[di++] = Dequeue(&buckets[bi]);
			}
		}

		// N��° �ڸ��� ���� ������ ���� �������� ����
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