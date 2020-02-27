#pragma once
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

typedef struct _employee
{
	int empNum;
	char name[20];
} Employee;

void SetEmployeeInfo(Employee*, const int, const char*);
void ShowEmployeeInfo(Employee*);

#endif // !__EMPLOYEE_H__
