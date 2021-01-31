#include <stdio.h>

void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < (size - i) - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// 데이터의 교환 ///////
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	int arr[4] = { 3, 2, 4, 1 };

	BubbleSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arr[i]);
	}

	puts("\n");
	return 0;
}