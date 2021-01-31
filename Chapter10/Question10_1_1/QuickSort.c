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
		// �ǹ����� ū ���� ã�� ����
		// low <= right ��� ������ �߰����� ������ �迭�� ���� ������ �Ѿ��.
		while (pivot >= arr[low] && low <= right)
		{
			low++;
		}

		// �ǹ����� ���� ���� ã�� ����
		// high >= (left + 1) ��� ������ �߰����� ������ �迭�� ���� ������ �Ѿ��.
		// left + 1 �� ���� ���ʿ� ��ġ�ϴ� �ǹ��� ���ܽ�Ű�� �����̴�.
		while (pivot <= arr[high] && high >= (left + 1))
		{
			high--;
		}

		// �������� ���� ���¶�� Swap ����
		if (low <= high)
		{
			Swap(arr, low, high);
		}
	}

	Swap(arr, left, high);		// �ǹ��� high �� ����Ű�� ��� ��ȯ
	return high;				// �Ű��� �ǹ��� ��ġ���� ��ȯ
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);		// �ѷ� ������
		QuickSort(arr, left, pivot - 1);				// ���� ������ ����
		QuickSort(arr, pivot + 1, right);				// ������ ������ ����
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