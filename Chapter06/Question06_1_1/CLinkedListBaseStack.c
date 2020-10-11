#include <stdio.h>
#include <stdlib.h>
#include "CLinkedListBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->plist = (List*)malloc(sizeof(List));
	ListInit(pstack->plist);
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->plist->numOfData == 0)
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
	LInsertFront(pstack->plist, data);
}

Data SPop(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		puts("Stack is Empty");
		return;
	}
	else
	{
		Data popData;
		LFirst(pstack->plist, &popData);
		LRemove(pstack->plist);
		return popData;
	}
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		puts("Stack is Empty");
		return;
	}
	else
	{
		Data data;
		LFirst(pstack->plist, &data);
		return data;
	}
}