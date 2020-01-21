#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	// ArrayList�� ���� �� �ʱ�ȭ ///////
	List list;
	int data;
	ListInit(&list);

	// 5���� ������ ���� ///////
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	// ����� �������� ��ü ��� ///////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))		// ù ��° ������ ��ȸ
	{
		printf("%d ", data);

		while (LNext(&list, &data))			// �� ��° ������ ������ ��ȸ
			printf("%d ", data);
	}
	printf("\n\n");

	// ���� 22�� Ž���Ͽ� ��� ���� ///////
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// ���� �� ���� ������ ��ü �ⷰ ///////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	
	// Question 03-1
	puts("Question 03-1");
	List list1;
	int sum = 0;
	ListInit(&list1);

	LInsert(&list1, 1);
	LInsert(&list1, 2);
	LInsert(&list1, 3);
	LInsert(&list1, 4);
	LInsert(&list1, 5);
	LInsert(&list1, 6);
	LInsert(&list1, 7);
	LInsert(&list1, 8);
	LInsert(&list1, 9);

	if (LFirst(&list1, &data))
	{
		sum += data;

		while (LNext(&list1, &data))
			sum += data;
	}
	printf("���� ���: %d \n", sum);

	if (LFirst(&list1, &data))
	{
		if ((data % 2 == 0) || (data % 3 == 0))
			LRemove(&list1);

		while (LNext(&list1, &data))
			if ((data % 2 == 0) || (data % 3 == 0))
				LRemove(&list1);
	}

	if (LFirst(&list1, &data))
	{
		printf("%d ", data);

		while (LNext(&list1, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}