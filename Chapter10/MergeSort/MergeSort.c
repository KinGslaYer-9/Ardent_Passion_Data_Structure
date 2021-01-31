#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int frontIndex = left;
	int rearIndex = mid + 1;

	// 병합한 결과를 담을 배열 동적 할당
	int* sortArray = (int*)malloc(sizeof(int) * (right + 1));
	int startIndex = left;

	while (frontIndex <= mid && rearIndex <= right)
	{
		// 병합 할 두 영역의 데이터들을 비교하여,
		// 정렬순서대로 sortArray 에 하나씩 옮겨 담는다.
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

	// 배열의 앞부분이 모두 sortArray 에 옮겨졌다면,
	if (frontIndex > mid)
	{
		// 배열의 뒷부분에 남은 데이터들을 sortArray 에 그대로 옮긴다.
		for (int i = rearIndex; i <= right; i++, startIndex++)
		{
			sortArray[startIndex] = arr[i];
		}
	}
	// 배열의 뒷부분이 모두 sortArray에 옮겨졌다면,
	else
	{
		// 배열의 앞부분에 남은 데이터들을 sortArray 에 그대로 옮긴다.
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

// 배열의 첫 번째 요소와 마지막 요소의 인덱스 값
void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)		// left 가 작다는 것은 더 나눌 수 있다는 뜻
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