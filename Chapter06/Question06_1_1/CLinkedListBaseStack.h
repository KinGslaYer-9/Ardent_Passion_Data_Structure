#ifndef __C_LINKED_LIST_BASE_STACK_H__
#define __C_LINKED_LIST_BASE_STACK_H__

#include "CLinkedList.h"

typedef struct cLinkedListBaseStack
{
	List* plist;
} CLinkedListBaseStack;

typedef CLinkedListBaseStack Stack;

void StackInit(Stack* pstack);

int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif // !__C_LINKED_LIST_BASE_STACK_H__
