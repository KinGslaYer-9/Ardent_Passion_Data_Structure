#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque* pdeq)
{
	if (pdeq->head == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void DQAddFirst(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pdeq->head;

	if (DQIsEmpty(pdeq))
	{
		pdeq->tail = newNode;
	}
	else
	{
		pdeq->head->prev = newNode;
	}

	pdeq->head = newNode;
	newNode->prev = NULL;
}

void DQAddLast(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = pdeq->tail;

	if (DQIsEmpty(pdeq))
	{
		pdeq->head = newNode;
	}
	else
	{
		pdeq->tail->next = newNode;
	}

	pdeq->tail = newNode;
	newNode->next = NULL;
}

Data DQRemoveFirst(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	Node* deleteNode = pdeq->head;
	Data returnData = deleteNode->data;

	pdeq->head = pdeq->head->next;
	free(deleteNode);

	if (pdeq->head == NULL)
	{
		pdeq->tail = NULL;
	}
	else
	{
		pdeq->head->prev = NULL;
	}

	return returnData;
}

Data DQRemoveLast(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	Node* deleteNode = pdeq->tail;
	Data returnData = deleteNode->data;

	pdeq->tail = pdeq->tail->prev;
	free(deleteNode);

	if (pdeq->tail == NULL)
	{
		pdeq->head = NULL;
	}
	else
	{
		pdeq->tail->next = NULL;
	}

	return returnData;
}

Data DQGetFirst(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pdeq->head->data;
}

Data DQGetLast(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pdeq->tail->data;
}