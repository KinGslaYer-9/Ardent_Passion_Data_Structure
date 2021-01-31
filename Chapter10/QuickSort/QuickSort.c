#include <stdio.h>

void Swap(int arr[], int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

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
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	// int arr[3] = { 3, 3, 3 };

	int len = sizeof(arr) / sizeof(int);
	
	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	puts("\n");
	return 0;
}