#include <stdio.h>

void SelectionSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int maxIdx = i;

		for (int j = i + 1; j < size; j++)    // ÃÖ¼Ú°ª Å½»ö
		{
			if (arr[j] < arr[maxIdx])
			{
				maxIdx = j;
			}
		}

		// ±³È¯ ///////
		int temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}

int main(void)
{
	int arr[4] = { 3, 4, 2, 1 };

	SelectionSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arr[i]);
	}

	puts("\n");
	return 0;
}