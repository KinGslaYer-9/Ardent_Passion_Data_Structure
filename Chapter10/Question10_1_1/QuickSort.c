#include <stdio.h>

void Swap(int arr[], int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

int SelectPivot(int arr[], int left, int right)
{
	int threeValues[3] = { left, (left + right) / 2, right };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2 - i; j++)
		{
			if (arr[threeValues[j]] > arr[threeValues[j + 1]])
			{
				Swap(threeValues, j, j + 1);
			}
		}
	}

	return threeValues[1];
}

int Partition(int arr[], int left, int right)
{
	int pivotIndex = SelectPivot(arr, left, right);
	int pivot = arr[pivotIndex];
	int low = left + 1;
	int high = right;

	Swap(arr, left, pivotIndex);

	printf("pivot : %d \n", pivot);

	while (low <= high)
	{
		// 피벗보다 큰 값을 찾는 과정
		// low <= right 라는 조건을 추가하지 않으면 배열의 정렬 범위를 넘어선다.
		while (pivot >= arr[low] && low <= right)
		{
			low++;
		}

		// 피벗보다 작은 값을 찾는 과정
		// high >= (left + 1) 라는 조건을 추가하지 않으면 배열의 정렬 범위를 넘어선다.
		// left + 1 은 가장 왼쪽에 위치하는 피벗을 제외시키기 위함이다.
		while (pivot <= arr[high] && high >= (left + 1))
		{
			high--;
		}

		// 교차되지 않은 상태라면 Swap 실행
		if (low <= high)
		{
			Swap(arr, low, high);
		}
	}

	Swap(arr, left, high);		// 피벗과 high 가 가리키는 대상 교환
	return high;				// 옮겨진 피벗의 위치정보 반환
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);		// 둘로 나눠서
		QuickSort(arr, left, pivot - 1);				// 왼쪽 영역을 정렬
		QuickSort(arr, pivot + 1, right);				// 오른쪽 영역을 정렬
	}
}

int main(void)
{
	int arr[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

	int len = sizeof(arr) / sizeof(int);

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	puts("\n");
	return 0;
}