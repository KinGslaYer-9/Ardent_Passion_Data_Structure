#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;			// LInsertFront �Լ����� ������ ������
	}

	(plist->numOfData)++;
}

void LInsertFront(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->tail == NULL)			// ����� ��尡 ���ٸ�
		return FALSE;

	plist->before = plist->tail;		// before�� ������ ����Ű�� �Ѵ�.
	plist->cur = plist->tail->next;		// cur�� �Ӹ��� ����Ű�� �Ѵ�.

	*pdata = plist->cur->data;			// cur�� ����Ű�� ����� ������ ��ȯ
	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->tail == NULL)			// ����� ��尡 ���ٸ�
		return FALSE;

	plist->before = plist->cur;			// before�� ���� ��带 ����Ű�� �Ѵ�.
	plist->cur = plist->cur->next;		// cur�� ���� ��带 ����Ű�� �Ѵ�.

	*pdata = plist->cur->data;			// cur�� ����Ű�� ����� ������ ��ȯ
	return TRUE;
}

Data LRemove(List* plist)
{
	Node* rNode = plist->cur;
	Data rData = rNode->data;

	if (rNode == plist->tail)
	{
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;		// �ٽɿ��� 1
	plist->cur = plist->before;					// �ٽɿ��� 2

	free(rNode);
	(plist->numOfData)--;
	return rData;
}

int LCount(List* plist)
{
	return plist->numOfData;
}