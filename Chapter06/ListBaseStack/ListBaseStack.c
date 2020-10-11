#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		puts("Stack is Empty");
		exit(-1);
	}
	else
	{
		Data popData = pstack->head->data;
		Node* freeNode = pstack->head;

		pstack->head = pstack->head->next;

		free(freeNode);
		return popData;
	}
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		puts("Stack is Empty");
		exit(-1);
	}
	else
	{
		return pstack->head->data;
	}
}