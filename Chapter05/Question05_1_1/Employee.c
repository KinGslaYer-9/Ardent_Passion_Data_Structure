#include <stdio.h>
#include <string.h>
#include "Employee.h"

void SetEmployeeInfo(Employee* emp, const int empNum, const char* name)
{
	emp->empNum = empNum;
	strcpy_s(emp->name, strlen(name) + 1, name);
}

void ShowEmployeeInfo(Employee* emp)
{
	printf("���: %d\n�̸�: %s\n\n", emp->empNum, emp->name);
}