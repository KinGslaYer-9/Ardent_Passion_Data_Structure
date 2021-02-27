#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1)
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
	if (pstack->topIndex >= ARRAY_LEN)
	{
		puts("Stack is Full");
		exit(-1);
	}
	else
	{
		(pstack->topIndex)++;
		pstack->arr[pstack->topIndex] = data;
	}
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
		int popIndex = pstack->topIndex;

		pstack->topIndex--;

		return pstack->arr[popIndex];
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
		return pstack->arr[pstack->topIndex];
	}
}