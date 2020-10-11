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
		plist->tail = newNode;			// LInsertFront 함수와의 유일한 차이점
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
	if (plist->tail == NULL)			// 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->tail;		// before가 꼬리를 가리키게 한다.
	plist->cur = plist->tail->next;		// cur이 머리를 가리키게 한다.

	*pdata = plist->cur->data;			// cur이 가리키는 노드의 데이터 반환
	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->tail == NULL)			// 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->cur;			// before가 다음 노드를 가리키게 한다.
	plist->cur = plist->cur->next;		// cur이 다음 노드를 가리키게 한다.

	*pdata = plist->cur->data;			// cur이 가리키는 노드의 데이터 반환
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

	plist->before->next = plist->cur->next;		// 핵심연산 1
	plist->cur = plist->before;					// 핵심연산 2

	free(rNode);
	(plist->numOfData)--;
	return rData;
}

int LCount(List* plist)
{
	return plist->numOfData;
}