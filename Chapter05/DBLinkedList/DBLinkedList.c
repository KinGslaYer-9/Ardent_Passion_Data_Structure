#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List* plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head;
	if (plist->head != NULL)
		plist->head->prev = newNode;

	newNode->prev = NULL;				// 새 노드의 prev를 NULL로 초기화
	plist->head = newNode;				// 포인터 변수 head가 새 노드 가리키게 함

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;		// cur이 첫 번째 노드를 가리키게 함

	*pdata = plist->cur->data;		// cur이 가리키는 노드의 데이터 반환
	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;		// cur을 오른쪽으로 이동

	*pdata = plist->cur->data;			// cur이 가리키는 노드의 데이터 반환
	return TRUE;
}

int LPrevious(List* plist, Data* pdata)
{
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;		// cur을 왼쪽으로 이동

	*pdata = plist->cur->data;			// cur이 가리키는 노드의 데이터 반환
	return TRUE;
}

int LCount(List* plist)
{
	return plist->numOfData;
}