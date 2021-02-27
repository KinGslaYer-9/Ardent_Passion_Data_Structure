#ifndef __ARRAYBASE_STACK_H__
#define __ARRAYBASE_STACK_H__

#define TRUE		1
#define FALSE		0
#define ARRAY_LEN	100

typedef int Data;

typedef struct arrayBaseStack
{
	int topIndex;
	Data arr[ARRAY_LEN];
} ArrayBaseStack;

typedef ArrayBaseStack Stack;

void StackInit(Stack* pstack);

int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif // !__ARRAYBASE_STACK_H__
