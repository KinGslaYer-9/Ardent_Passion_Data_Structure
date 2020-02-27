#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"

Employee* WhosAfterDayDuty(List*, const char*, const int);

int main(void)
{
	List list;
	Employee* emp;
	int afterDay = 2;
	const char* name = "�ڸ��";

	ListInit(&list);

	emp = (Employee*)malloc(sizeof(Employee));
	SetEmployeeInfo(emp, 25, "���缮");
	LInsert(&list, emp);

	emp = (Employee*)malloc(sizeof(Employee));
	SetEmployeeInfo(emp, 223, "������");
	LInsert(&list, emp);

	emp = (Employee*)malloc(sizeof(Employee));
	SetEmployeeInfo(emp, 185, "�ڸ��");
	LInsert(&list, emp);

	emp = (Employee*)malloc(sizeof(Employee));
	SetEmployeeInfo(emp, 330, "������");
	LInsert(&list, emp);

	if (LFirst(&list, &emp))
	{
		ShowEmployeeInfo(emp);
		for (int i = 0; i < LCount(&list) - 1; i++)
		{
			if(LNext(&list, &emp))
				ShowEmployeeInfo(emp);
		}
	}
	printf("\n");

	emp = WhosAfterDayDuty(&list, name, afterDay);
	printf("%s�� �ٹ��� �� %d�� �� ������ \n\n", name, afterDay);
	ShowEmployeeInfo(emp);
	printf("�Դϴ�. \n");

	return 0;
}

Employee* WhosAfterDayDuty(List* plist, const char* name, const int afterDay)
{
	Employee* afterDayDutyInfo;

	LFirst(plist, &afterDayDutyInfo);

	for (int i = 0; i < LCount(plist) - 1; i++)
	{
		if (strcmp(afterDayDutyInfo->name, name) == 0)
			break;
		else
			LNext(plist, &afterDayDutyInfo);
	}

	for (int i = 0; i < afterDay; i++)
		LNext(plist, &afterDayDutyInfo);

	return afterDayDutyInfo;
}