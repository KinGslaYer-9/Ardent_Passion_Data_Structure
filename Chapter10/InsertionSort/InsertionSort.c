#include <stdio.h>

void InsertionSort(int arr[], int size)
{
	int j;

	for (int i = 1; i < size; i++)
	{
		int insertData = arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insertData)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}

		arr[j + 1] = insertData;
	}
}

int main(void)
{
	int arr[5] = { 5, 3, 2, 4, 1 };
	
	InsertionSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}

	puts("\n");
	return 0;
}