#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

#define CUS_COME_TERM	15

#define CHE_BUR		0
#define BUL_BUR		1
#define DUB_BUR		2

#define CHE_TERM	12
#define BUL_TERM	15
#define DUB_TERM	24

int main(void)
{
	int makeProc = 0;
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec;

	Queue que;

	QueueInit(&que);
	srand(time(NULL));

	for (sec = 0; sec < 3600; sec++)
	{
		if (sec % CUS_COME_TERM == 0)			// 15초에 1회씩 TRUE 가 된다.
		{
			switch (rand() % 3)
			{
			case CHE_BUR:
				Enqueue(&que, CHE_TERM);		// 치즈버거 주문 후 대기실 이동
				cheOrder += 1;
				break;

			case BUL_BUR:
				Enqueue(&que, BUL_TERM);		// 불고기버거 주문 후 대기실 이동
				bulOrder += 1;
				break;

			case DUB_BUR:
				Enqueue(&que, DUB_BUR);			// 더블버거 주문 후 대기실 이동
				dubOrder += 1;
				break;
			}
		}

		if (makeProc <= 0 && !QIsEmpty(&que))
		{
			makeProc = Dequeue(&que);			// 대기실에서 나와서 대기한다.
		}

		makeProc--;
	}

	printf("Simulation Report! \n");
	printf(" - Cheese burger: %d \n", cheOrder);
	printf(" - Bulgogi burger: %d \n", bulOrder);
	printf(" - Double burger: %d \n", dubOrder);
	printf(" - Waiting room size: %d \n", QUEUE_LENGTH);
	return 0;
}