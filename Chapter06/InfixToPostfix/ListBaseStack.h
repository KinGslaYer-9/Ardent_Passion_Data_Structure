#ifndef __LISTBASE_STACK_H__
#define __LISTBASE_STACK_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct listBaseStack
{
	Node* head;
} ListBaseStack;

typedef ListBaseStack Stack;

void StackInit(Stack* pstack);

int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif // !__LISTBASE_STACK_H__
