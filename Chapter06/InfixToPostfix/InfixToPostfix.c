#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrec(char op)			// 연산자의 우선순위 정보를 반환한다.
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;			// 가장 높은 연산의 우선순위
	case '+':
	case '-':
		return 3;			// 5보다 작고 1보다 높은 연산의 우선순위
	case '(':
		return 1;			// 가장 낮은 연산의 우선순위
	}

	return -1;				// 등록되지 않은 연산자임을 알림!
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)				// op1의 우선순위가 더 높다면
		return 1;
	else if (op1Prec < op2Prec)			// op2의 우선순위가 더 높다면
		return -1;
	else
		return 0;						// op1과 op2의 우선순위가 같다면
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen + 1);		// 변환된 수식을 담을 공간 마련

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1);			// 할당된 배열을 0으로 초기화
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];

		if (isdigit(tok))		// tok에 저장된 문자가 숫자인지 확인
		{
			convExp[idx++] = tok;		// 숫자이면 배열 convExp에 그냥 저장
		}
		else		// 숫자가 아니라면(연산자라면)
		{
			switch (tok)
			{
			case '(':						// 여는 소괄호라면,
				SPush(&stack, tok);			// 스택에 넣는다.
				break;

			case ')':						// 닫는 소괄호라면,
				while (1)					// 반복해서,
				{
					popOp = SPop(&stack);		// 스택에서 연산자를 꺼내어,
					if (popOp == '(')			// 연산자 ( 을 만날 때까지,
						break;
					convExp[idx++] = popOp;		// 배열 convExp에 저장한다.
				}
				break;

			case '+': case '-':
			case '*': case '/':
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);
				SPush(&stack, tok);
				break;
			}
		}
	}

	while (!SIsEmpty(&stack))					// 스택에 남아 있는 모든 연산자를,
		convExp[idx++] = SPop(&stack);			// 배열 convExp로 이동한다.

	strcpy_s(exp, expLen + 1, convExp);		// 변환된 수식을 exp에 복사하고,
	free(convExp);				// convExp는 소멸시킨다.
}