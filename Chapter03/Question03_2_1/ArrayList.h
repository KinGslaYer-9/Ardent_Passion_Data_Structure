#pragma once
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include "NameCard.h"

#define TRUE		1		// '��'�� ǥ���ϱ� ���� ��ũ�� ����
#define FALSE		0		// '����'�� ǥ���ϱ� ���� ��ũ�� ����

#define LIST_LEN	100
typedef NameCard* LData;			// LData�� ���� typedef ����(�پ��� ���¸� �����ϱ� ����, int �κ��� �ٸ� �ڷ������� �ٲٸ� �ȴ�.)

typedef struct __ArrayList		// �迭��� ����Ʈ�� ������ ����ü
{
	LData arr[LIST_LEN];		// ����Ʈ�� ������� �迭
	int numOfData;				// ����� �������� ��
	int curPosition;			// ������ ������ġ�� ���
} ArrayList;

typedef ArrayList List;		// ����ϴ� ����Ʈ�� ������ �ٲٱ� ���ؼ�(main �Լ��� ������ �ʿ� ����.)

void ListInit(List* plist);						// �ʱ�ȭ
void LInsert(List* plist, LData data);			// ������ ����

int LFirst(List* plist, LData* pdata);			// ù ������ ����
int LNext(List* plist, LData* pdata);			// �� ��° ���� ������ ����

LData LRemove(List* plist);						// ������ ������ ����
int LCount(List* plist);						// ����� �������� �� ��ȯ

#endif // !__ARRAY_LIST_H__
