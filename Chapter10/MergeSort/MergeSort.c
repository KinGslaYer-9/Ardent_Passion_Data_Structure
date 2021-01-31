#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int frontIndex = left;
	int rearIndex = mid + 1;

	// ������ ����� ���� �迭 ���� �Ҵ�
	int* sortArray = (int*)malloc(sizeof(int) * (right + 1));
	int startIndex = left;

	while (frontIndex <= mid && rearIndex <= right)
	{
		// ���� �� �� ������ �����͵��� ���Ͽ�,
		// ���ļ������ sortArray �� �ϳ��� �Ű� ��´�.
		if (arr[frontIndex] <= arr[rearIndex])
		{
			sortArray[startIndex] = arr[frontIndex++];
		}
		else
		{
			sortArray[startIndex] = arr[rearIndex++];
		}

		startIndex++;
	}

	// �迭�� �պκ��� ��� sortArray �� �Ű����ٸ�,
	if (frontIndex > mid)
	{
		// �迭�� �޺κп� ���� �����͵��� sortArray �� �״�� �ű��.
		for (int i = rearIndex; i <= right; i++, startIndex++)
		{
			sortArray[startIndex] = arr[i];
		}
	}
	// �迭�� �޺κ��� ��� sortArray�� �Ű����ٸ�,
	else
	{
		// �迭�� �պκп� ���� �����͵��� sortArray �� �״�� �ű��.
		for (int i = frontIndex; i <= mid; i++, startIndex++)
		{
			sortArray[startIndex] = arr[i];
		}
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = sortArray[i];
	}

	free(sortArray);
}

// �迭�� ù ��° ��ҿ� ������ ����� �ε��� ��
void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)		// left �� �۴ٴ� ���� �� ���� �� �ִٴ� ��
	{
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };

	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (int i = 0; i < 7; i++)
	{
		printf("%d ", arr[i]);
	}

	puts("\n");
	return 0;
}